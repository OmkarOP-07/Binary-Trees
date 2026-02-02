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

int check_balanced_tree(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lh = check_balanced_tree(root->left);
    int rh = check_balanced_tree(root->right);

    if (lh == -1 && rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;

    return max(lh, rh) + 1;
}

int main()
{
    TreeNode *root = new TreeNode(
        1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3));

    int ans = check_balanced_tree(root);
    cout << ans;
    return 0;
}