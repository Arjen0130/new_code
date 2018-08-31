#include <iostream>

#include <vector>
#include <string>
#include <map>

using namespace std;

/*
题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出0。
题解：
  方法1：
    使用map记录每个值出现的次数。但是这种方法的复杂度相对较高。
  方法2：
    参考讨论区中的解题方式，采用不同数值相消的方法。
*/

class Solution {
public:

    // // 方法1：
    // int MoreThanHalfNum_Solution(vector<int> numbers) {
    //     map<int, int> num_count;
    //     int num_size = numbers.size();
    //     for (int i = 0; i < num_size; i++)
    //     {
    //         map<int, int>::iterator iter = num_count.find(numbers[i]);
    //         if (iter == num_count.end())
    //         {
    //             num_count.insert(pair<int, int>(numbers[i], 1));
    //         }
    //         else
    //         {
    //             num_count[numbers[i]] += 1;
    //             if (num_count[numbers[i]] > (num_size / 2))
    //                 return numbers[i];
    //         }
    //     }
    //     map<int, int>::iterator iter_end = num_count.end();
    //     for (map<int, int>::iterator iter = num_count.begin(); iter != iter_end; ++iter)
    //     {
    //         if (iter->second > (num_size / 2))
    //         {
    //             return iter->first;
    //         }
    //     }
    //     return 0;
    // }

    // 方法2：
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int num_size = numbers.size();
        if (0 == num_size)
        {
            return 0;
        }
        if (1 == num_size)
        {
            return numbers[0];
        }
        int ret = numbers[0];
        int count = 1;
        for (int i = 1; i < num_size; i++)
        {
            if (0 == count)
            {
                ret = numbers[i];
                count = 1;
            }
            else
            {
                if (ret == numbers[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }

        count = 0;
        for (int i = 0; i < num_size; i++)
        {
            if (ret == numbers[i])
            {
                count++;
            }
        }
        if (count*2 <= num_size)
        {
            ret = 0;
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    // int array_tmp[9] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    // vector<int> vec(array_tmp, array_tmp+9);
    vector<int> vec(1, 1);
    cout << solution.MoreThanHalfNum_Solution(vec) << endl;
    return 0;
}