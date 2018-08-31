#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：给定一个double类型的浮点数base和int类型的整数exponent。
求base的exponent次方。
*/

class Solution {
public:
    double Power(double base, int exponent) {
        if (0 == exponent)
        {
            return 1;
        }
        bool flag = false;
        if (0 > exponent)
        {
            exponent = exponent * (-1);
            flag = true;
        }
        double ret = 1;
        for (int i = 0; i < exponent; i++)
        {
            ret = ret * base;
        }
        if (true == flag)
        {
            ret = 1 / ret;
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    return 0;
}