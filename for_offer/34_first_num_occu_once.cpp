#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<int> vec_times(256, 0);
        vector<int> vec_pos(256, -1);

        int size = str.size();
        for (int i = 0; i < size; i++)
        {
            char char_tmp = str[i];
            vec_times[char_tmp]++;
            if (1 == vec_times[char_tmp])
                vec_pos[char_tmp] = i;
        }

        int min_pos = size;
        for (int i = 0; i < 256; i++)
        {
            if ((1 == vec_times[i]) && (min_pos > vec_pos[i]))
            {
                min_pos = vec_pos[i];
            }
        }
        return min_pos == size ? -1 : min_pos;
    }
};

int main()
{
    Solution solution;
    return 0;
}