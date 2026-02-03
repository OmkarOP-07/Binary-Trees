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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool LtoR = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                // find posi
                int index = (LtoR) ? i : (size - 1 - i);

                row[index] = temp->val;
                if (temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            LtoR = !LtoR;
            ans.push_back(row);
        }
        return ans;
    }
};

int main()
{
    TreeNode *p = new TreeNode(
        1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3));
    Solution sh;
    vector<vector<int>> ans = sh.zigzagLevelOrder(p);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ",";
        }
        cout << "]";
    }

    return 0;
}