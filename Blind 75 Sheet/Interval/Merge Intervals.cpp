#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
    vector<vector<int>> v = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> ans;
    for(auto i : v){
        int st = i[0], end = i[1];

        if(ans.empty() or st > ans.back()[1]) ans.push_back(i);
        else ans.back()[1] = max(ans.back()[1], i[1]);
    }
    for(auto i : ans) cout << i[0] << " " << i[1] << endl;

}