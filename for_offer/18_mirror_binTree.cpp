#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：操作给定的二叉树，将其变换为源二叉树的镜像。
输入：
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
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
    void Mirror(TreeNode *pRoot) {
        if (NULL == pRoot)
        {
            return;
        }
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        TreeNode * pTmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTmp;
    }
};

int main()
{
    Solution solution;
    return 0;
}