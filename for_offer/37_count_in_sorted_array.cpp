#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
题目：统计一个数字在排序数组中出现的次数。
题解：
  方法1：
    直接使用 stl 中的 equal_range 函数，查找有序数列中某个元素的范围。
  方法2：
    自行实现二分查找算法，然后，通过该算法查找某个元素的范围。
*/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        pair<vector<int>::iterator, vector<int>::iterator> iter;
        iter = equal_range(data.begin(), data.end(), k);
        return (iter.second - iter.first);
    }
};

int main()
{
    Solution solution;
    return 0;
}