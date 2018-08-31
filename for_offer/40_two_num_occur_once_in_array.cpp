#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。
请写程序找出这两个只出现一次的数字。
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int size = data.size();
        if ((NULL == num1) || (NULL == num2) || (2 > size) || (3 == size))
            return;
        if ((2 == size) && (data[0] != data[1]))
        {
            * num1 = data[0];
            * num2 = data[1];
        }

        int xor_tmp = data[0];
        for (int i = 1; i < size; i++)
        {
            xor_tmp ^= data[i];
        }

        int xor_tmp_flag = 1;
        while (0 == (xor_tmp_flag & xor_tmp))
        {
            xor_tmp_flag = xor_tmp_flag << 1;
        }

        vector<int> vec_1;
        vector<int> vec_2;
        for (int i = 0; i < size; i++)
        {
            if (0 == (data[i] & xor_tmp_flag))
            {
                vec_1.push_back(data[i]);
            }
            else
            {
                vec_2.push_back(data[i]);
            }
        }

        * num1 = vec_1[0];
        size = vec_1.size();
        for (int i = 1; i < size; i++)
        {
            * num1 = ((* num1) ^ vec_1[i]);
        }
        * num2 = vec_2[0];
        size = vec_2.size();
        for (int i = 1; i < size; i++)
        {
            * num2 = ((* num2) ^ vec_2[i]);
        }
    }
};

int main()
{
    Solution solution;
    return 0;
}