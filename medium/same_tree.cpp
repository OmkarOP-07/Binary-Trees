#include<iostream>
#include<bits/stdc++.h>
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


class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return 1;
        if(p == NULL || q == NULL) return 0;
        if(p->val != q->val) return 0;
        bool lh = isSameTree(p->left,q->left);
        bool rh = isSameTree(p->right,q->right);

        if(lh && rh) return true;
        else return false;
    }
};


int main()
{
    TreeNode *p = new TreeNode(
        1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3));
    TreeNode *q = new TreeNode(
        1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3));
    Solution sh;
    cout<<sh.isSameTree(p,q);
 return 0;
}