#include <iostream>

#include <vector>
#include <string>
#include <math.h>

using namespace std;

/*
题目：把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。
求按从小到大的顺序的第N个丑数。
题解：
  方法1：
    按照丑数的定义，从小到达逐个判断各个数是否为丑数，并对丑数的个数进行计数。
    这种方式会超时。
  方法2：
    根据丑数的特点，从小到大构造各个丑数。
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 7)
            return index;
        vector<int> vec(index, 1);
        
        int t1 = 0, t2 = 0, t3 = 0;
        for (int i = 1; i < index; i++)
        {
            vec[i] = min(vec[t1] * 2, min(vec[t2] * 3, vec[t3] * 5));
            if (vec[i] == vec[t1] * 2)
                t1++;
            if (vec[i] == vec[t2] * 3)
                t2++;
            if (vec[i] == vec[t3] * 5)
                t3++;
        }
        return vec[index - 1];
    }
};

int main()
{
    Solution solution;
    cout << solution.GetUglyNumber_Solution(4) << endl; 
    return 0;
}