#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    vector<vector<int>> v = {{1, 2}, {2,3}, {3, 4}, {1, 3}};

    sort(v.begin(), v.end());
    int st = v[0][0], end = v[0][1];
    int ans = 0;

    for(int i=1; i<v.size(); i++){
        if(v[i][0] < end) ans++;
        else end = v[i][1];
    }
    cout << ans;
}