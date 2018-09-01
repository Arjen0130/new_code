#include <iostream>

#include <vector>
#include <string>
#include <list>

using namespace std;

/*
题目：
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
        
        list<TreeNode *> list_l2r;
        list<TreeNode *> list_r2l;
        bool flag = false;

        list_l2r.push_back(pRoot);

        while((! list_l2r.empty()) || (! list_r2l.empty()))
        {
            if (false == flag)
            {
                list_opera(ret, list_l2r, list_r2l, flag);
            }
            else
            {
                list_opera(ret, list_r2l, list_l2r, flag);
            }
        }
        
        return ret;
    }
private:
    void list_opera(vector<vector<int> > & ret, list<TreeNode *> & list_pop, list<TreeNode *> & list_push, bool & flag)
    {
        vector<int> vec;
        while (! list_pop.empty())
        {
            TreeNode * tmp = list_pop.back();
            list_pop.pop_back();
        
            vec.push_back(tmp->val);
            if (false == flag)
            {
                if (NULL != tmp->left)
                    list_push.push_back(tmp->left);
                if (NULL != tmp->right)
                    list_push.push_back(tmp->right);
            }
            else
            {
                if (NULL != tmp->right)
                    list_push.push_back(tmp->right);
                if (NULL != tmp->left)
                    list_push.push_back(tmp->left);
            }
        }
        flag = ! flag;
        ret.push_back(vec);
    }
};

int main()
{
    Solution solution;
    return 0;
}