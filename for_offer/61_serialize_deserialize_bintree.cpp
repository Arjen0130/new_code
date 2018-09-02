#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
    请实现两个函数，分别用来序列化和反序列化二叉树
题解：
    参考自牛客网。
    使用vector<int>保存二叉树节点中的数据；
    使用二叉树的先根遍历将各个节点保存到vector中；
    使用特殊int值表示叶子节点；
    使用二叉树的先根遍历，并结合叶子节点特殊值恢复二叉树。
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
    char* Serialize(TreeNode *root) {    
        vec.clear();
        dfs_serialize(root);

        int size = vec.size();
        int * i_tmp = new int[size];  // 注意，new 数组的时候，要使用中括号[]
        for (int i = 0; i < size; i++)
        {
            i_tmp[i] = vec[i];
        }
        return (char *)i_tmp;
    }

    TreeNode* Deserialize(char *str) {
        int * p_int = (int *)str;
        return dfs_deserialize(p_int);
    }
private:
    void dfs_serialize(TreeNode * root)
    {
        if (NULL == root)
        {
            vec.push_back(0x7fffffff);
            return;
        }
        vec.push_back(root->val);
        dfs_serialize(root->left);
        dfs_serialize(root->right);
    }

    TreeNode * dfs_deserialize(int * & p)
    {
        if ( 0x7fffffff== (*p))
        {
            ++p;
            return NULL;
        }
        TreeNode * ret = new TreeNode(*p);
        ++p;
        ret->left = dfs_deserialize(p);
        ret->right = dfs_deserialize(p);
        return ret;
    }
    
private:
    vector<int> vec;
};

int main()
{
    Solution solution;
    return 0;
}