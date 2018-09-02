#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
    请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
    路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
    如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
    例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
    但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

class Solution 
{
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if ((NULL == matrix) || (NULL == str) || (0 >= rows) || (0 >= cols))
            return false;

        vector<vector<bool> > mark(rows, vector<bool>(cols, false));       

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (true == dfs_path(matrix, mark, i, j, rows, cols, str))
                    return true;
            }
        }
        return false;
    }
private:
    bool dfs_path(char * mat, vector<vector<bool> > & mark, 
                  int x, int y, int rows, int cols, 
                  char * str)
    {
        if ('\0' == *str)
            return true;
        if ((false == mark[x][y]) && (mat[x*cols+y] == *str))
        {
            if ('\0' == *(str+1))
                return true;
            mark[x][y] = true;
            if (((x + 1 < rows) && (dfs_path(mat, mark, x+1, y, rows, cols, str+1))) ||
                ((y + 1 < cols) && (dfs_path(mat, mark, x, y+1, rows, cols, str+1))) ||
                ((x > 0) && (dfs_path(mat, mark, x-1, y, rows, cols, str+1))) ||
                ((y > 0) && (dfs_path(mat, mark, x, y-1, rows, cols, str+1))))
                return true;
            mark[x][y] = false;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    char matrix[] = {'a', 'b', 'c', 'e', 's', 'f', 'c', 's', 'a', 'd', 'e', 'e'};
    char str[] = {'b', 'c', 'c', 'e', 'd'};
    cout << solution.hasPath(matrix, 3, 4, str) << endl;
    return 0;
}