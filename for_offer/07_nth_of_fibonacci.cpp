#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/

class Solution {
public:
    int Fibonacci(int n) {
        vector<int> vec(40, 0);
        vec[0] = 0;
        vec[1] = 1;
        for (int i = 2; i <= 39; i++)
        {
            vec[i] = vec[i - 1] + vec[i - 2];
        }
        return vec[n];
    }
};

int main()
{
    Solution solution;
    return 0;
}