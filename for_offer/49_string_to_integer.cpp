#include <iostream>

#include <math.h>

#include <vector>
#include <string>

using namespace std;

/*
题目：
    将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
    但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
    数值为0或者字符串不是一个合法的数值则返回0。
输入：
    输入一个字符串,包括数字字母符号,可以为空
输出：
    如果是合法的数值表达则返回该数字，否则返回0
示例：
  输入：
    +2147483647
    1a33
  输出：
    2147483647
    0
题解：
  方法1：
    使用比较笨的方法逐步对字符串进行分析，然后转换为数值；
  方法2：
    参考牛客上的解法。
*/

class Solution_2
{
public:
    int StrToInt(string str) {
        int size = str.size();
        if (0 == size)
        {
            return 0;
        }

        int sign = 1;
        if ('-' == str[0])
            sign = -1;

        int res = 0;
        for (int i = ((str[0] == '+') || (str[0] == '-')) ? 1 : 0; i < size; i++)
        {
            if (('0' > str[i]) || ('9' < str[i]))
            {
                return 0;
            }
            // res = res * 10 + ((int) str[i] - '0');
            res = (res << 1) + (res << 3) + (str[i] & 0xf);
        }
        return sign * res;
    }
};

class Solution_1 
{
public:
    int StrToInt(string str) {
        int sign, sta;
        if (true == is_digit_string(str, sign, sta))
        {
            return sign * str_to_int(str, sta);
        }
        else
        {
            return 0;
        }
    }
private:
    int str_to_int(string str, int sta)
    {
        int size = str.size();
        int len = size - sta;

        int sum = 0;
        for (int i = sta; i < size; i++)
        {
            int num = (int)(str[i] - '0');
            int mul = pow(10, len - 1);
            len--;
            sum += (num * mul);
        }

        return sum;
    }

    bool is_digit_string(string str, int & sign, int & sta)
    {
        int size = str.size();
        if (0 == size)
        {
            return false;
        }

        char c_tmp = str[0];
        if (1 == size)
        {
            if (('9' < c_tmp) || ('0' > c_tmp))
            {
                return false;
            }
            else
            {
                sign = 1;
                sta = 0;
                return true;
            }
        }
        else
        {
            if ('+' == c_tmp)
            {
                sign = 1;
                sta = 1;
            }
            else if ('-' == c_tmp)
            {
                sign = -1;
                sta = 1;
            }
            else if (('9' < c_tmp) || ('0' > c_tmp))
            {
                return false;
            }
            else
            {
                sign = 1;
                sta = 0;
            }

            for (int i = sta; i < size; i++)
            {
                c_tmp = str[i];
                if (('9' < c_tmp) || ('0' > c_tmp))
                {
                    return false;
                }
            }
            return true;
        }
    }
};

int main()
{
    Solution_2 solution;
    cout << solution.StrToInt("1a33") << endl;
    return 0;
}