#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
    vector<vector<int>> v = {{1,2}, {3,5}, {6,7}, {8,10}, {13, 16}};
    vector<int> to = {11, 12};
    vector<vector<int>> ans;
    int i = 0, n = v.size();

    while(i<n and to[0] > v[i][1]){
        ans.push_back(v[i]); i++;
    }

    if(i == n) ans.push_back(to);
    else{
        while(i<n and to[1] >= v[i][0]){
            to[0] = min(to[0], v[i][0]);
            to[1] = max(v[i][1], to[1]); i++;
        }
        ans.push_back(to);
        while(i<n){
            ans.push_back(v[i]);
            i++;
        }
    }

    for(auto i : ans) cout << i[0] << " " << i[1] << endl;

}