#include <iostream>

#include <vector>
#include <string>
#include <list>

using namespace std;

/*
题目：
    从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution 
{
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ret;
        if (NULL == pRoot)
            return ret;
        
        list<TreeNode *> list_tmp;
        list_tmp.push_back(pRoot);
        vector<int> vec;
        int count = 1;

        while (! list_tmp.empty())
        {
            TreeNode * p_tmp = list_tmp.front();
            list_tmp.pop_front();

            vec.push_back(p_tmp->val);
            if (NULL != p_tmp->left)
                list_tmp.push_back(p_tmp->left);
            if (NULL != p_tmp->right)
                list_tmp.push_back(p_tmp->right);
            
            count--;
            if (0 == count)
            {
                ret.push_back(vec);
                vec.clear();
                count = list_tmp.size();
            }
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    return 0;
}