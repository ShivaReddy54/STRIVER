#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<string> v = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;

    for(auto i : v){
        string w = i;
        sort(w.begin(), w.end());
        mp[w].push_back(i);
    }

    for(auto i : mp) ans.push_back(i.second);
    
    for(auto i : ans){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
}