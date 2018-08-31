#include <iostream>

#include <vector>

using namespace std;

/*
题目：在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rowsNum = array.size();
        int colsNum = array[0].size();
        int i = 0;
        int j = colsNum - 1;
        while (i < rowsNum && j >= 0)
        {
            if (array[i][j] > target)
            {
                j--;
            }
            else if (array[i][j] < target)
            {
                i++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int> > array;

    for(int rowNum = 0; rowNum < 10; rowNum++)
    {
        vector<int> tmp;
        for (int colNum = 0; colNum < 10; colNum++)
        {
            tmp.push_back(rowNum * colNum);
        }
        array.push_back(tmp);
    }

    Solution solution;
    cout << "The find result is " << solution.Find(4, array) << endl;
    return 0;
}