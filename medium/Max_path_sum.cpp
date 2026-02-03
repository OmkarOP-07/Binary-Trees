#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxPath(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        int lh = max(0, maxPath(root->left, maxi));
        int rh = max(0, maxPath(root->right, maxi));

        maxi = max(maxi, root->val + lh + rh);
        return root->val + max(lh, rh);
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
};

int main()
{
    TreeNode *root = new TreeNode(
        1,
        new TreeNode(2),
        new TreeNode(3));
    Solution sh;
    cout << sh.maxPathSum(root);
    return 0;
}
