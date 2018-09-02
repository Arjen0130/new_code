#include <iostream>

#include <vector>
#include <string>
#include <queue>

using namespace std;

/*
题目：
    如何得到一个数据流中的中位数？
    如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
    如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
    我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
题解：
    参考自牛客网。
    使用一个大根堆和一个小根堆存放数据。
*/

class Solution
{
public:
    void Insert(int num)
    {
        if ((min_heap.empty()) || (num < min_heap.top()))
            max_heap.push(num);
        else
        {
            min_heap.push(num);
        }

        if (max_heap.size() + 2 == min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if (max_heap.size() == min_heap.size() + 2)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }  
    }

    double GetMedian()
    {
        if (max_heap.size() == min_heap.size())
        {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
        else
        {
            if (max_heap.size() > min_heap.size())
                return max_heap.top();
            else
                return min_heap.top();      
        }
    }

private:
    int count;
    priority_queue<int, vector<int>, less<int> > max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
};

class Solution_1
{
public:
    Solution_1 (): count(0) {}

    void Insert(int num)
    {
        count++;
        if (0 == count % 2)
        {
            int tmp = max_heap.top();
            if (num < tmp)
            {
                max_heap.pop();
                max_heap.push(num);
                min_heap.push(tmp);
            }
            else
            {
                min_heap.push(num);
            }
        }
        else
        {
            if (min_heap.empty())
            {
                max_heap.push(num);
            }
            else
            {
                int tmp = min_heap.top();
                if (num < tmp)
                {
                    max_heap.push(num);
                }
                else
                {
                    min_heap.pop();
                    min_heap.push(num);
                    max_heap.push(tmp);
                }  
            }
        }
    }

    double GetMedian()
    { 
        if (1 == count % 2)
        {
            return (double)max_heap.top();
        }
        else
        {
            return (min_heap.top() + max_heap.top()) / 2.0;
        }
        
    }

private:
    int count;
    priority_queue<int, vector<int>, less<int> > max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
};

int main()
{
    Solution solution;
    return 0;
}