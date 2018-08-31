#include <iostream>

#include <vector>
#include <string>
#include <queue>

using namespace std;

/*
题目：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> vec_ret;
        if (NULL != root)
        {
            queue_tmp.push(root);
            while (! queue_tmp.empty())
            {
                TreeNode * p_node_tmp = queue_tmp.front();
                queue_tmp.pop();
                
                vec_ret.push_back(p_node_tmp->val);
                if (NULL != p_node_tmp->left)
                {
                    queue_tmp.push(p_node_tmp->left);
                }
                if (NULL != p_node_tmp->right)
                {
                    queue_tmp.push(p_node_tmp->right);
                }
            }
        }
        return vec_ret;
    }

private:
    queue<TreeNode *> queue_tmp;
};

int main()
{
    Solution solution;
    return 0;
}