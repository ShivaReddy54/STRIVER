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
    bool ans = 0;
    bool help(TreeNode* root, TreeNode* sub){
        if(!root and !sub) return 1;
        if(!root or !sub or root->val != sub->val) return 0;

        return help(root->left, sub->left) and help(root->right, sub->right);
    }

    void inorder(TreeNode* root, TreeNode* sub){
        if(!root) return;

        inorder(root->left, sub);
        if(help(root, sub)) ans = 1;
        inorder(root->left, sub);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        inorder(root, subRoot);
        return ans;
    }
};