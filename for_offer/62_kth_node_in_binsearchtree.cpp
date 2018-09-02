#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
    给定一棵二叉搜索树，请找出其中的第k小的结点。
    例如,（5，3，7，2，4，6，8)中，按结点数值大小顺序第三小结点的值为4。
*/

class Solution 
{
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        int count = 0;
        return kth_node(pRoot, k, count);
    }
private:
    TreeNode * kth_node(TreeNode * p_root, int k, int & count)
    {
        if (NULL != p_root)
        {
            TreeNode * p_left = kth_node(p_root->left, k, count);
            if (NULL != p_left)
                return p_left;
            
            count++;
            if (k == count)
                return p_root;
            
            TreeNode * p_right = kth_node(p_root->right, k, count);
            if (NULL != p_right)
                return p_right;
        }
        return NULL;
    }
};

int main()
{
    Solution solution;
    return 0;
}