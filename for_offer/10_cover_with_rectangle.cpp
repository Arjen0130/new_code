#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

class Solution {
public:
    int rectCover(int number) {
        if (2 >= number)
        {
            return number;
        }
        vector<int> vec(number+1, 0);
        vec[1] = 1;
        vec[2] = 2;
        for (int i = 3; i <= number; i++)
        {
            vec[i] = vec[i - 1] + vec[i - 2];
        }
        return vec[number];
    }
};

int main()
{
    Solution solution;
    return 0;
}