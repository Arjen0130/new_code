#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
*/

class Solution 
{
public:
    bool isNumeric(char* str_tmp)
    {
        int E_pos;
        string str(str_tmp);
        if (true == has_E(str, E_pos))
        {
            string str_1 = str.substr(0, E_pos);
            string str_2 = str.substr(E_pos + 1, str.size() - E_pos - 1);
            return (is_int(str_1) || is_float(str_1)) && (is_int(str_2));
        }
        else
        {
            return is_int(str) || is_float(str);
        }
    }
private:
    bool has_E(string str, int & E_pos)
    {
        int size = str.size();
        for (int i = 0; i < size; i++)
        {
            if (('E' == str[i]) || ('e' == str[i]))
            {
                E_pos = i;
                return true;
            } 
        }   
        return false;
    }

    bool is_int(string str)
    {
        int size = str.size();
        if (0 == size)
            return false;

        bool flag = false;  // 用于确保字符串中不是仅仅只有一个正、负号
        for (int i = (('+' == str[0]) || ('-' == str[0])) ? 1 : 0; i < size; i++)
        {
            if ((str[i] < '0') || (str[i] > '9'))
                return false;
            flag = true;
        }
        return flag;
    }

    bool is_float(string str)
    {
        int size = str.size();
        if (0 == size)
            return false;
        
        bool dot_flag = false;
        for (int i = (('+' == str[0]) || ('-' == str[0])) ? 1 : 0; i < size; i++)
        {
            if (((str[i] < '0') || (str[i] > '9')) && ('.' != str[i]))
                return false;
            else if ('.' == str[i])
            {
                if (true == dot_flag)
                    return false;
                else
                {
                    dot_flag = true;
                }
            }
        }
        return dot_flag;
    }
};

int main()
{
    Solution solution;
    return 0;
}