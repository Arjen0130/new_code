#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
    地上有一个m行和n列的方格。
    一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
    例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
    但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
    请问该机器人能够达到多少个格子？
题解：
    参考自牛客网。
    采用广度优先遍历算法。
*/

class Solution 
{
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if ((0 >= rows) || (0 >= cols))
            return 0;

        vector<vector<bool> > mark(rows, vector<bool>(cols, false));
        return helper(mark, 0, 0, rows, cols, threshold);
    }
private:
    int helper(vector<vector<bool> > & mark, int x, int y, int rows, int cols, int threshold)
    {
        if ((x < 0) || 
            (y < 0) ||
            (x >= rows) ||
            (y >= cols) ||
            (true == mark[x][y]) ||
            (sumIndex(x) + sumIndex(y) > threshold))
            return 0;
        
        mark[x][y] = true;

        return 1 + helper(mark, x+1, y, rows, cols, threshold) 
                 + helper(mark, x-1, y, rows, cols, threshold)
                 + helper(mark, x, y+1, rows, cols, threshold)
                 + helper(mark, x, y-1, rows, cols, threshold);

    }
    int sumIndex(int num)
    {
        int sum = 0;
        
        while (0 != num)
        {
            sum += (num % 10);
            num = num / 10;
        }
        
        return sum;
    }
};

int main()
{
    Solution solution;
    return 0;
}