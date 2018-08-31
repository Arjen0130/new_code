#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
    给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
    其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
    不能使用除法。
*/

class Solution 
{
public:
    vector<int> multiply(const vector<int>& A) {
        int size = A.size();
        vector<int> tmp;
        if (0 == size)
            return tmp;
            
        vector<int> left(size, 1), right(size, 1), ret(size, 1);

        for (int i = 1; i < size; i++)
        {
            left[i] = (left[i - 1] * A[i - 1]);
            right[size - i - 1] = (right[size - i] * A[size - i]);
        }

        for (int i = 0; i < size; i++)
        {
            ret[i] = left[i] * right[i];
        }

        return ret;
    }
};

int main()
{
    Solution solution;
    return 0;
}