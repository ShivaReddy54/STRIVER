#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> ans;
void help(vector<int>& v, int i, int tar, vector<int>& t){
    if(tar == 0){
        sort(t.begin(), t.end());
        ans.push_back(t);
        return;
    }
    if(tar < 0 or i < 0) return;

    t.push_back(v[i]);
    help(v, i, tar-v[i], t);
    t.pop_back();

    help(v, i-1, tar, t);
}


int main(){
    vector<int> v = {2,3,5}; int tar = 8, n = v.size();
    vector<int> t;

    help(v, n-1, tar, t);

    for(auto i : ans){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
}