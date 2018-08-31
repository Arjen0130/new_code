#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
题目：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode * tree_root = NULL;
        if (0 != pre.size())
        {
            buildBinTree(tree_root, pre, 0, pre.size(), vin, 0, vin.size());
        }
        return tree_root;
    }

    void buildBinTree(TreeNode * &root, const vector<int> & pre, int pre_sta, int pre_end, const vector<int> & vin, int vin_sta, int vin_end)
    {
        if (pre_sta >= pre_end)
        {
            return;
        }
        int mid_val = pre[pre_sta];
        vector<int>::const_iterator mid_iter = find(vin.begin()+vin_sta, vin.begin()+vin_end, mid_val);
        if (mid_iter == vin.end())
        {
            return;
        }
        int mid_index = mid_iter - vin.begin();
        int left_num = mid_index - vin_sta;
        int right_num = vin_end - mid_index - 1;
        root = new TreeNode(pre[pre_sta]);
        int left_sub_pre_sta = pre_sta + 1;
        int left_sub_pre_end = pre_sta + 1 + left_num;
        int left_sub_vin_sta = vin_sta;
        int left_sub_vin_end = vin_sta + left_num;
        int right_sub_pre_sta = left_sub_pre_end;
        int right_sub_pre_end = pre_end;
        int right_sub_vin_sta = mid_index + 1;
        int right_sub_vin_end = vin_end;
        buildBinTree(root->left, pre, left_sub_pre_sta, left_sub_pre_end, vin, left_sub_vin_sta, left_sub_vin_end);
        buildBinTree(root->right, pre, right_sub_pre_sta, right_sub_pre_end, vin, right_sub_vin_sta, right_sub_vin_end);
    }
};

int main()
{
    Solution solution;
    int array_pre[8] = {1, 2, 4, 7, 3, 5 ,6, 8};
    int array_vin[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    vector<int> pre(array_pre, array_pre+8);
    vector<int> vin(array_vin, array_vin+8);
    TreeNode * root_ret = solution.reConstructBinaryTree(pre, vin);
    return 0;
}