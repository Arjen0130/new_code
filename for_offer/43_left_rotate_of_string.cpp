#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
题目：
    汇编语言中有一种移位指令叫做循环左移（ROL）。
    现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
    对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
    例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
    是不是很简单？OK，搞定它！
题解：
  方法1：
    通过拼接两个字符串，然后取出其中偏移为n，长度与原长度相同的字串即可。
  方法2：
    使用 STL 中定义好的旋转算法。
*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
        return method_2(str, n);
    }
private:
    string method_1(string str, int n)
    {
        int size = str.size();
        if (0 == size)
            return "";
        if (n >= size)
            n = n % size;
        string tmp = str + str;
        tmp = tmp.substr(n, size);
        return tmp;
    }

    string method_2(string str, int n)
    {
        rotate(str.begin(), str.begin() + n, str.end());
        return str;
    }
};

int main()
{
    Solution solution;
    string str = "abcXYZdef";
    cout << solution.LeftRotateString(str, 3) << endl;
    return 0;
}