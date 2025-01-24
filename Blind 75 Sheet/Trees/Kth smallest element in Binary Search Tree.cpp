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
    int ans = 0;
    void help(TreeNode* root, int& k){
        if(!root) return;

        help(root->left, k);

        if(k){
            ans = root->val; k--;
        }

        help(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        help(root, k);
        return ans;
    }
};