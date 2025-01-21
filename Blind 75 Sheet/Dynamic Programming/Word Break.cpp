#include <bits/stdc++.h>
using namespace std;
#define ll long long


class Trie{
public:
    bool end;
    Trie* child[26];

    Trie(){
        end = 0;
        for(int i=0; i<26; i++) child[i] = nullptr;
    }
}; Trie* root = new Trie();

void insert(string& s){
    Trie* t = root;

    for(auto i : s){
        int ind = i - 'a';

        if(!t->child[ind]) t->child[ind] = new Trie();
        t = t->child[ind];
    }
    t->end = 1;
}

bool help(string& s, int i, vector<int>& dp){
    if(i >= s.size()) return 1;
    if(dp[i] != -1) return dp[i];

    Trie* t = root;
    for(int j=i; j<s.size(); j++){
        int ind = s[j] - 'a';

        if(!t->child[ind]) return dp[i] = 0;
        t = t->child[ind];
        if(t->end and help(s, j+1, dp)) return dp[i] = 1;
    }

    return dp[i] = 0;
}

int main(){
    vector<string> dict = {"cats","dog","sand","and","cat"};
    for(auto i : dict) insert(i);

    string s = "catsandog";
    int n = s.size();

    vector<int> dp(n+1, -1);
    cout << help(s, 0, dp);


}
