#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
    请实现一个函数，用来判断一颗二叉树是不是对称的。
    注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
题解：
  方法1：
    建立树的右子树的镜像；
    然后遍历左子树和右子树的镜像结果，并在遍历的过程中逐个节点对比。
    这种处理方式比较繁琐，并且目前的实现会修改原始树的结构。
    如果不修改原始树的结构，就需要重新分配新的内存空间存储镜像树。
  方法2：
    参考牛客网。
    首先根节点以及其左右子树，左子树的左子树和右子树的右子树相同
    左子树的右子树和右子树的左子树相同即可，采用递归
    非递归也可，采用栈或队列存取各级子树根节点
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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (NULL == pRoot)
            return true;
        return compare(pRoot->left, pRoot->right);
    }
private:
    bool compare(TreeNode * left, TreeNode * right)
    {
        if ((NULL == left) && (NULL == right))
            return true;
        if (((NULL == left) && (NULL != right)) || 
            ((NULL != left) && (NULL == right)))
            return false;
        
        if (left->val != right->val)
            return false;
        
        return (compare(left->left, right->right) && compare(left->right, right->left)); 
    }
};

class Solution_1
{
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (NULL == pRoot)
        {
            return true;
        }
        mirror_tree(pRoot->right);
        return is_mirror(pRoot->left, pRoot->right);
    }
private:
    bool is_mirror(TreeNode * p_root_1, TreeNode * p_root_2)
    {
        if ((NULL == p_root_1) && (NULL == p_root_2))
            return true;
        if (((NULL == p_root_1) && (NULL != p_root_2)) || 
            ((NULL != p_root_1) && (NULL == p_root_2)))
            return false;
        
        bool flag_1 = (p_root_1->val == p_root_2->val);
        bool flag_2 = is_mirror(p_root_1->left, p_root_2->left);
        bool flag_3 = is_mirror(p_root_1->right, p_root_2->right);
        return (flag_1 && flag_2 && flag_3); 
    }

    void mirror_tree(TreeNode * p_root)
    {
        if (NULL == p_root)
            return;
        TreeNode * p_tmp = p_root->left;
        p_root->left = p_root->right;
        p_root->right = p_tmp;

        mirror_tree(p_root->left);
        mirror_tree(p_root->right);
    }
};

int main()
{
    Solution solution;
    return 0;
}