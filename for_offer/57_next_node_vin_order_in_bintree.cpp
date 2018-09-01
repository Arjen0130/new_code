#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
    给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
    注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
    }
};

class Solution 
{
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (NULL == pNode)
            return NULL;
        if (NULL != pNode->right)
        {
            pNode = pNode->right;
            while (NULL != pNode->left)
            {
                pNode = pNode->left;
            }
            return pNode;
        }
        TreeLinkNode * p_root = pNode->next;
        while ((NULL != p_root) && (p_root->left != pNode))
        {
            pNode = p_root;
            p_root = p_root->next;
        }
        return p_root;
    }
};

int main()
{
    Solution solution;
    return 0;
}