#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
题目：定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

class Solution {
public:
    void push(int value) {
        stack.push_back(value);
    }
    void pop() {
        stack.pop_back();
    }
    int top() {
        return stack.back();
    }
    int min() {
        return * min_element(stack.begin(), stack.end());
    }
private:
    vector<int> stack;
};

int main()
{
    Solution solution;
    solution.push(1);
    solution.push(5);
    solution.push(0);
    solution.push(2);
    cout << solution.top() << endl;
    cout << solution.min() << endl;
    solution.pop();
    cout << solution.top() << endl;
    return 0;
}