#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxi = 0;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int depth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lmax = depth(root->left);
    int rmax = depth(root->right);

    maxi = max(lmax+rmax, maxi);
    return 1 + max(lmax, rmax);
}

int main()
{
    TreeNode *root = new TreeNode(
        1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3));
    depth(root);
    cout<<maxi;
    return 0;
}
