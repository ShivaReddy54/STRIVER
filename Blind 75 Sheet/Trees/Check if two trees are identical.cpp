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

    bool help(TreeNode* p, TreeNode* q){
        if(!p and !q) return 1;
        if(!p or !q or p->val != q->val) return 0;

        return help(p->left, q->left) and help(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return help(p, q);
    }
};