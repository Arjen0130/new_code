#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
        {
            return false;
        }
        else
        {
            return is_post_traverse_result(sequence, 0, sequence.size());
        }
    }
private:
    bool is_post_traverse_result(vector<int> & vec, int vec_sta, int vec_end)
    {
        if (vec_sta >= vec_end)
        {
            return true;
        }

        int mid_tmp = vec[vec_end - 1];
        bool flag = false;
        bool index = vec_sta;
        for (int i = vec_sta; i < vec_end; i++)
        {
            if (mid_tmp > vec[i])
            {
                if (true == flag)
                {
                    return false;
                }
            }
            else
            {
                if (false == flag)
                {
                    flag = true;
                    index = i;
                }
            }
        }
        bool left_flag = is_post_traverse_result(vec, vec_sta, index);
        bool right_flag = is_post_traverse_result(vec, index, vec_end - 1);
        return (left_flag && right_flag);
    }
};

int main()
{
    Solution solution;
    return 0;
}