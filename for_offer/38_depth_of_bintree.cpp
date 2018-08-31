#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
题解：
  方法1：
    使用递归算法求解，代码量极少。
  方法2：
    使用二叉树的层序遍历算法求解。
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
    int TreeDepth(TreeNode* pRoot)
    {
        if (NULL == pRoot)
        {
            return 0;
        }
        return (1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)));
    }
};

int main()
{
    Solution solution;
    return 0;
}