#include "sort\quickSort.h"

void QuickSort::sort(vector<int> &nums)
{
    sort(nums, 0, nums.size() - 1);
}

void QuickSort::sort(vector<int> &nums, int left, int right)
{
    //��������֮ǰ���ж�һ�µ�ǰ����������Ԫ�ظ����ǲ��Ǵ���1 �����û�б�Ҫ����
    if (left >= right)
    {
        //ֱ���˳��������  û�б�Ҫ����������
        return;
    }

    //��ʼ���п����㷨
    //���������ȱ���left������Ӧ������  ��ǰ������Ϊ�и��������
    int piovt = nums[left];

    //������ʱ������������2�˵�����
    int leftIndex = left;
    int rightIndex = right;

    while (leftIndex < rightIndex)
    {
        //��������ͨ��ѭ�����ұ߿�ʼ����һ������ֵС������
        while (leftIndex < rightIndex)
        {
            //����ұߵ������ڵ�ǰ�Ĳ�����ֵ
            if (piovt <= nums[rightIndex])
            {
                //�Ҷ�����ָʾ������
                rightIndex--;
            }
            else
            {
                //˵�������Ҷ˳��ֱ���ֵ���������
                //���ʱ�����ǾͿ��԰���������������䵽������������Ӧ�ĵط�
                nums[leftIndex] = nums[rightIndex];
                leftIndex++;
                //������Ҫ����ѭ���˵�ǰ�������
                break;
            }
        }

        //����߿�ʼ����һ������ֵ���������д�ϴ����µĿ�
        while (leftIndex < rightIndex)
        {
            //�����ߵ�����С����ֵ ��������ָʾ����������
            if (piovt >= nums[leftIndex])
            {
                leftIndex++;
            }
            else
            {
                //˵������������ҵ��˱���ֵ���������
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

