#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入一个整数，输出该数二进制表示中1的个数。
其中负数用补码表示。
*/

class Solution {
public:
    int  NumberOf1(int n) {
         int count = 0;
         while (n != 0)
         {
             n = (n & (n - 1));
             count++;
         }
         return count;
    }
};

int main()
{
    Solution solution;
    return 0;
}