#include <iostream>

#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

/*
题目：输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
题解：
  使用最小堆。
*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        int input_size = input.size();
        if (0 == input_size || k <= 0 || k > input_size)
        {
            return ret;
        }

        priority_queue<int> queue_tmp;
        for (int i = 0; i < input_size; i++)
        {
            if (queue_tmp.size() < k)
            {
                queue_tmp.push(input[i]);
            }
            else 
            {
                if (queue_tmp.top() > input[i])
                {
                    queue_tmp.pop();
                    queue_tmp.push(input[i]);
                }
            }
        }

        while (! queue_tmp.empty())
        {
            ret.push_back(queue_tmp.top());
            queue_tmp.pop();
        }
        // reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    Solution solution;
    int array_tmp[8] = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> vec(array_tmp, array_tmp+8);
    vector<int> ret = solution.GetLeastNumbers_Solution(vec, 4);
    return 0;
}