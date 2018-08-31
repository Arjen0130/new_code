#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列;
但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int size_push = pushV.size();
        int size_pop = popV.size();
        if ((0 == size_push) || (0 == size_pop) || (size_push != size_pop))
        {
            return false;
        }
        int push_index = 0;
        int pop_index = 0;
        
        while ((push_index < size_push) || (! stack.empty()) && (stack.back() == popV[pop_index]))
        {
            if ((! stack.empty()) && (stack.back() == popV[pop_index]))
            {
                stack.pop_back();
                pop_index++;
            }
            else 
            {
                stack.push_back(pushV[push_index]);
                push_index++;
            }
        }
        return stack.empty();
    }

private:
    vector<int> stack;
};

int main()
{
    Solution solution;
    int array_push[5] = {1, 2, 3, 4, 5};
    int array_pop[5] = {4, 5, 3, 2, 1};
    vector<int> push_v(array_push, array_push+5);
    vector<int> pop_v(array_pop, array_pop+5);
    cout << solution.IsPopOrder(push_v, pop_v) << endl;
    return 0;
}