#pragma once

#include <vector>
#include <thread>
#include <numeric>
#include <algorithm>
#include <windows.h>
using namespace std;

template<typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T& result)
    {
        Sleep(10000);
        result = std::accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    unsigned long const length = distance(first, last);
    if (!length) return init;

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
    unsigned long const hardware_threads = thread::hardware_concurrency();
    unsigned long const num_threads = min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    unsigned long const block_size = length / num_threads;

    vector<T> results(num_threads);
    vector<thread> threads(num_threads - 1);

    Iterator block_start = first;
    for (unsigned long i = 0; i < (num_threads - 1); ++i)
    {
        Iterator block_end = block_start;
        advance(block_end, block_size);

        threads[i] = thread(accumulate_block<Iterator, T>(), block_start, block_end, ref(results[i]));
        block_start = block_end;
    }

    // 先让主线程执行最后一组数据的加法，再执行join，以免主线程浪费时间等待子线程执行完
    accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

    // 这里如果是detach，程序会直接执行下一句。如果是join，会等待目前线程执行完毕，再执行下一句
    for_each(threads.begin(), threads.end(), mem_fn(&thread::detach));
    // for_each(threads.begin(), threads.end(), mem_fn(&thread::join));


    return accumulate(results.begin(), results.end(), init);

    return init;
}