#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n = 5;
    vector<int> ans(n+1);

    for(int i=0; i<=n; i++){
        int cnt = 0;
        for(int j=0; j<32; j++) cnt += (i >> j) & 1;
        ans[i] = cnt;
    }
    for(auto i : ans) cout << i << " ";
}