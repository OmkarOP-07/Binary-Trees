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

void inprepost(TreeNode *root)
{
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    vector<int> in, pre, post;
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->val);
        }
    }
    cout << "PreOrder Traversal :";
    for (auto it : pre)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "InOrder Traversal :";
    for (auto it : in)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "PostOrder Traversal :";
    for (auto it : post)
    {
        cout << it << " ";
    }
}

int main()
{
    TreeNode* root = new TreeNode(
        1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3)
    );
    inprepost(root);

    return 0;
}