#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (NULL == pRoot2)
        {
            return false;
        }
        return traverse_tree(pRoot1, pRoot2);
    }

private:
    bool traverse_tree(TreeNode * p_root_1, TreeNode * p_root_2)
    {
        if (NULL == p_root_1)
        {
            return false;
        }

        if (match_tree(p_root_1, p_root_2))
        {
            return true;
        }
        else
        {
            return ((match_tree(p_root_1->left, p_root_2)) || (match_tree(p_root_1->right, p_root_2)));
        }
    }

    bool match_tree(TreeNode * p_root_1, TreeNode * p_root_2)
    {
        if ((NULL != p_root_1) && (NULL != p_root_2))
        {
            bool flag_tmp = (match_tree(p_root_1->left, p_root_2->left) && match_tree(p_root_1->right, p_root_2->right));
            return ((p_root_1->val == p_root_2->val) && flag_tmp);
        }

        if ((NULL == p_root_2))
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution solution;
    return 0;
}