#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int size = numbers.size();
        if (0 == size)
        {
            return "";
        }
        if (1 == size)
        {
            return to_string(numbers[0]);
        }

        sort(numbers.begin(), numbers.end(), cmp);
        
        string str;
        for (int i = 0; i < size; i++)
        {
            str += to_string(numbers[i]);
        }
        return str;

    }
private:
    static bool cmp(int num_1, int num_2)
    {
        string str_1 = to_string(num_1) + to_string(num_2);
        string str_2 = to_string(num_2) + to_string(num_1);
        return str_1 < str_2;
    }
};

int main()
{
    Solution solution;
    int array_tmp[3] = {3, 32, 321};
    vector<int> vec(array_tmp, array_tmp+3);
    cout << solution.PrintMinNumber(vec) << endl;
    return 0;
}