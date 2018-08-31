#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16，
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        int rowNum = matrix.size();
        if (0 == rowNum)
        {
            return ret;
        }
        int colNum = matrix[0].size();

        int rowSta = 0, rowEnd = rowNum - 1;
        int colSta = 0, colEnd = colNum - 1;
        while ((rowSta <= rowEnd) && (colSta <= colEnd))
        {
            printMatrixSub(ret, matrix, rowSta, rowEnd, colSta, colEnd);
        }
        return ret;
    }

    void printMatrixSub(vector<int> &ret, vector<vector<int> > &matrix, 
        int & rowSta, int & rowEnd, 
        int & colSta, int & colEnd)
    {
        if (rowSta == rowEnd)
        {
            while (colSta <= colEnd)
            {
                ret.push_back(matrix[rowSta][colSta++]);
            }
            return;
        }
        if (colSta == colEnd)
        {
            while (rowSta <= rowEnd)
            {
                ret.push_back(matrix[rowSta++][colSta]);
            }
            return;
        }

        int i = rowSta;
        int j = colSta;
        while (j < colEnd)
        {
            ret.push_back(matrix[i][j++]); 
        }
        while (i < rowEnd)
        {
            ret.push_back(matrix[i++][j]);
        }
        while (j > colSta)
        {
            ret.push_back(matrix[i][j--]);
        }
        while (i > rowSta)
        {
            ret.push_back(matrix[i--][j]);
        }
        rowSta++;
        rowEnd--;
        colSta++;
        colEnd--;

    }

};

int main()
{
    vector<vector<int> > matrix;
    int count = 1;
    for (int i = 0; i < 5; i++)
    {
        vector<int> row;
        for (int j = 0; j < 1; j++)
        {
            row.push_back(count++);
        }
        matrix.push_back(row);
    }

    Solution solution;
    vector<int> ret = solution.printMatrix(matrix);

    int size = ret.size();
    for (int i = 0; i < size; i++)
    {
        cout << " " << ret[i];
    }
    cout << endl;
    return 0;
}