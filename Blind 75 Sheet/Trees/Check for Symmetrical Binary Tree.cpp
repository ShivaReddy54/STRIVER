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

bool help(TreeNode* a, TreeNode* b){
    if(!a and !b) return 1;
    if(!a or !b or a->val != b->val) return 0;
    
    return help(a->left, b->right) and help(a->right, b->left);
}

bool sym(TreeNode* root){
    return help(root->left, root->right);
}
