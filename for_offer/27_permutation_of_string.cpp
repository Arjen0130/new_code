#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
题目：输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ret;
        if (str.empty())
            return ret;
        // permu("", str, ret);
        permu_2(str, ret);
        sort(ret.begin(), ret.end());
        // stl 中的 unique 函数去除的是相邻的重复元素
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
private:
    // 方式1：使用递归计算全排列
    void permu(string res, string rem, vector<string> & ret)
    {
        if (rem.empty())
        {
            ret.push_back(res);
        }
        else
        {
            int rem_size = rem.size();
            for (int i = 0; i < rem_size; i++)
            {
                string res_tmp = res + rem[i];
                string rem_tmp = rem;
                // 删除 string 中特定下标的字符时，需要使用迭代器
                rem_tmp.erase(rem_tmp.begin() + i);
                permu(res_tmp, rem_tmp, ret);
            }
        }
    }

    // 方式2：使用 STL 算法获得全排列
    void permu_2(string str, vector<string> & ret)
    {
        sort(str.begin(), str.end());
        do
        {
            ret.push_back(str);
        }while(next_permutation(str.begin(), str.end()));
    }
};

int main()
{
    Solution solution;
    string str = "aab";
    vector<string> ret = solution.Permutation(str);
    int ret_size = ret.size();
    for (int i = 0; i < ret_size; i++)
    {
        cout << ret[i] << endl;
    }
    return 0;
}