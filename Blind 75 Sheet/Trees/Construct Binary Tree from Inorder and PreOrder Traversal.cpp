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

    int findd(vector<int>& a, int st, int end, int tar){
        for(int i=st; i<=end; i++)
            if(a[i] == tar) return i;
        return -1;
    }

    TreeNode* help(vector<int>& a, vector<int>& b, int st, int end, int rt){
        if(st > end) return nullptr;

        TreeNode* root = new TreeNode(b[rt]);
        int index = findd(a, st, end, b[rt]);

        root->left = help(a, b, st, index-1, rt+1);
        root->right = help(a, b, index+1, end, rt+(index - st) + 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
        int n = preorder.size();

        return help(inorder, preorder, 0, n-1, 0);
    }
};