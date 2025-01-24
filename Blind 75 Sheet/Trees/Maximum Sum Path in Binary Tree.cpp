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

    int ans = INT_MIN;

    int help(TreeNode* root){
        if(!root) return 0;

        int l = max(0, help(root->left));
        int r = max(0, help(root->right));

        int curr = root->val + l + r;
        ans = max(ans,curr);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        help(root);
        return ans;
    }
};