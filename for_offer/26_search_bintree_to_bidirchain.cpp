#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
题解：
  参考讨论区，使用递归方法
  1.将左子树构造成双链表，并返回链表头节点。
  2.定位至左子树双链表最后一个节点。
  3.如果左子树链表不为空的话，将当前root追加到左子树链表。
  4.将右子树构造成双链表，并返回链表头节点。
  5.如果右子树链表不为空的话，将该链表追加到root节点之后。
  6.根据左子树链表是否为空确定返回的节点。
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (NULL == pRootOfTree)
        {
            return NULL;
        }
        if ((NULL == pRootOfTree->left) && (NULL == pRootOfTree->right))
        {
            return pRootOfTree;
        }

        TreeNode * p_tmp_left = Convert(pRootOfTree->left);
        TreeNode * p_tmp_right = Convert(pRootOfTree->right);
        
        TreeNode * p_tmp_rear = p_tmp_left;
        if (NULL != p_tmp_left)
        {
            while (NULL != p_tmp_rear->right)
            {
                p_tmp_rear = p_tmp_rear->right;
            }
            p_tmp_rear->right = pRootOfTree;
            pRootOfTree->left = p_tmp_rear;
        }
        
        if (NULL != p_tmp_right)
        {
            p_tmp_right->left = pRootOfTree;
            pRootOfTree->right = p_tmp_right;
        }
        
        return (NULL != p_tmp_left) ? p_tmp_left : pRootOfTree;
    }
};

int main()
{
    Solution solution;
    return 0;
}