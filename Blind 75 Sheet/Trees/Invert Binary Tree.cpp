#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void help(TreeNode* root){
        if(!root) return;

        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;

        help(root->left);
        help(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        help(root);
        return root;
    }
};