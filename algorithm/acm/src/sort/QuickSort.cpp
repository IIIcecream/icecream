#include "sort\quickSort.h"

void QuickSort::sort(vector<int> &nums)
{
    sort(nums, 0, nums.size() - 1);
}

void QuickSort::sort(vector<int> &nums, int left, int right)
{
    //快速排序之前先判断一下当前待排序数组元素个数是不是大于1 否则就没有必要排序
    if (left >= right)
    {
        //直接退出排序代码  没有必要进行排序了
        return;
    }

    //开始进行快排算法
    //首先我们先保存left索引对应的数据  当前数据作为切割数组的轴
    int piovt = nums[left];

    //定义临时变量保存数组2端的索引
    int leftIndex = left;
    int rightIndex = right;

    while (leftIndex < rightIndex)
    {
        //现在我们通过循环从右边开始搜索一个比轴值小的数据
        while (leftIndex < rightIndex)
        {
            //如果右边的数大于当前的参数轴值
            if (piovt <= nums[rightIndex])
            {
                //右端索引指示器左移
                rightIndex--;
            }
            else
            {
                //说明我们右端出现比轴值更大的数据
                //这个时候我们就可以把这个更大的数据填充到索引轴索引对应的地方
                nums[leftIndex] = nums[rightIndex];
                leftIndex++;
                //我们需要跳出循环了当前工作完毕
                break;
            }
        }

        //从左边开始搜索一个比轴值更大的数填写上次留下的坑
        while (leftIndex < rightIndex)
        {
            //如果左边的数据小于轴值 我们索引指示器就往右走
            if (piovt >= nums[leftIndex])
            {
                leftIndex++;
            }
            else
            {
                //说明我们在左端找到了比轴值更大的数据
                nums[rightIndex] = nums[leftIndex];
                rightIndex--;
                break;
            }
        }
    }

    nums[leftIndex] = piovt;

    sort(nums, left, leftIndex - 1);
    sort(nums, rightIndex + 1, right);
}

