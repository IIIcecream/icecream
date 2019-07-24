
#include <iostream>

#include "ThreadDemo.h"

int main()
{
    vector<int> vec;
    for (int i = 0; i < 100; ++i)
    {
        vec.push_back(i);
    }

    int sum = 0;
    sum = parallel_accumulate<std::vector<int>::iterator, int>(vec.begin(), vec.end(), sum);

    std::cout << "Hello World!\n"; 
}