#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    vector<vector<int>> v = {{10, 20}, {12,25}, {20,30}};
    sort(v.begin(), v.end());

    int ans = 0, end = -1;
    for(int i=0; i<v.size(); i++){
        if(v[i][0] > end){
            ans++;
            end = v[i][1];
        }
    }
    cout << ans;
}