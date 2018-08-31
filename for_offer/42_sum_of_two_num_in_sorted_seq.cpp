#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
    输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S;
    如果有多对数字的和等于S，输出两个数的乘积最小的。
输出：
    对应每个测试案例，输出两个数，小的先输出。
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ret;

        int size = array.size();
        if (2 > size)
            return ret;

        int sta = 0, end = size - 1;
        while (sta < end)
        {
            int sum_tmp = array[sta] + array[end];
            if (sum_tmp < sum)
            {
                sta++;
            }
            else if (sum_tmp > sum)
            {
                end--;
            }
            else
            {
                ret.push_back(array[sta]);
                ret.push_back(array[end]);
                break;
            }
        }

        return ret;
    }
};

int main()
{
    Solution solution;
    return 0;
}