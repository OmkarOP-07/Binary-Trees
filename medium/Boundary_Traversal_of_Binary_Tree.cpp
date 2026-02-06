#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution {
  public:
    bool isLeaf(Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }
    return false;
}

void helper(Node *root, vector<int> &ans)
{
    if(root == NULL) return;
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    helper(root->left, ans);
    helper(root->right, ans);
    return;
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans;
    if(root == NULL) return ans;
    
    if(!isLeaf(root))
        ans.push_back(root->data);

    Node *temp = root->left;
    while(temp){
    if(!isLeaf(temp)) ans.push_back(temp->data);

    if(temp->left) temp = temp->left;
    else temp = temp->right;
    }

    helper(root, ans);
    temp = root->right;
    stack<int> st;
    while(temp){
    if(!isLeaf(temp)) st.push(temp->data);

    if(temp->right) temp = temp->right;
    else temp = temp->left;
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    Solution sh;
    vector<int> boundary = sh.boundaryTraversal(root);

    for (int x : boundary)
        cout << x << " ";

    return 0;
}