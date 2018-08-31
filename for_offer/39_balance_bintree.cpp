#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入一棵二叉树，判断该二叉树是否是平衡二叉树。
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return (-1 != depth(pRoot));
    }

private:
    int depth(TreeNode * root)
    {
        if (NULL == root)
            return 0;
        int depth_left = depth(root->left);
        int depth_right = depth(root->right);
        if ((depth_left >= 0) && (depth_right >= 0) && (abs(depth_left - depth_right) <= 1))
        {
            return max(depth_left, depth_right) + 1;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    return 0;
}