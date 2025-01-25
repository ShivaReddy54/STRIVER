#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> v = {1,1,1,2,2,3};
    int k = 2;
    unordered_map<int, int> mp;
    for(auto i : v) mp[i]++;

    vector<pair<int, int>> t;
    for(auto i : mp) t.push_back({i.second, i.first});
    sort(t.rbegin(), t.rend());

    vector<int> ans; int i=0;
    while(k--) ans.push_back(t[i++].second);

    for(auto i : ans) cout << i << " ";
}