#include <iostream>

#include <vector>
#include <string>
#include <deque>

using namespace std;

/*
题目：
    给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
    例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
    那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
    针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
    {[2,3,4],2,6,2,5,1}， 
    {2,[3,4,2],6,2,5,1}， 
    {2,3,[4,2,6],2,5,1}， 
    {2,3,4,[2,6,2],5,1}， 
    {2,3,4,2,[6,2,5],1}， 
    {2,3,4,2,6,[2,5,1]}。
题解：
    参考自牛客网。
    使用双端队列存储数组中元素的下标；
    在遍历数组的过程中，如果新加入的元素比队列尾部的元素大，那么就弹出队列尾部的元素，直到不满足该条件或队列为空为止；
    如果队列首部的元素已经在超过滑动窗口范围，那么就弹出队列首部的元素，直到不满足该条件或队列为空为止；
    将当前数组元素的下标加入队列尾部；
    如果如果检测过的元素数已经大于滑动窗口大小，那么队列首部的元素就是当前滑动窗口的最大值。
*/

class Solution 
{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ret;
        deque<int> qu;
        int len = num.size();
        for (int i = 0; i < len; i++)
        {
            while ((0 != qu.size()) && (num[qu.back()] < num[i]))
                qu.pop_back();
            while ((0 != qu.size()) && (i - qu.front() >= size))
                qu.pop_front();
            qu.push_back(i);
            if ((0 < size) && (i + 1 >= size))
                ret.push_back(num[qu.front()]);
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    return 0;
}