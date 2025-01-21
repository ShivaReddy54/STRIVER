#include <bits/stdc++.h>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:

    unordered_map<int, Node*> mp;
    Node* dfs(Node* node){
        if(mp[node->val]) return mp[node->val];
        mp[node->val] = new Node(node->val);

        for(auto i : node->neighbors)
            mp[node->val]->neighbors.push_back(dfs(i));
        

        return mp[node->val];
    }

    Node* cloneGraph(Node* node) {
        if(node==nullptr) return node;
        return dfs(node);
    }
};