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
    bool help(TreeNode* root, long long lower, long long higher){
        if(!root) return 1;
        if(root->val <= lower or root->val >= higher) return 0;

        return help(root->left, lower, root->val) and help(root->right, root->val, higher);
    }

    bool isValidBST(TreeNode* root) {
        return help(root, LLONG_MIN, LLONG_MAX);
    }
};