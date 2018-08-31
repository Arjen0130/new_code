#include <iostream>

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

/*
题目：输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > ret;
        vector<int> path;
        if (NULL != root)
            find_path(ret, path, root, expectNumber);
        sort(ret.begin(), ret.end(), is_longer);
        return ret;
    }
private:
    static bool is_longer(vector<int> & vec_1, vector<int> & vec_2)
    {
        return vec_1.size() >= vec_2.size();
    }

    void find_path(vector<vector<int> > & ret, vector<int> path, TreeNode * root, const int expectNumber)
    {
        path.push_back(root->val);
        
        if ((NULL == root->left) && (NULL == root->right))
        {
            int sum = accumulate(path.begin(), path.end(), 0);
            if (sum == expectNumber)
            {
                ret.push_back(path);
            }
        }

        if (NULL != root->left)
        {
            find_path(ret, path, root->left, expectNumber);
        }
        if (NULL != root->right)
        {
            find_path(ret, path, root->right, expectNumber);
        }
    }
};

int main()
{
    Solution solution;
    return 0;
}