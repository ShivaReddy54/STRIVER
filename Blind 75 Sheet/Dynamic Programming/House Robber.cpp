#include <bits/stdc++.h>
using namespace std;
#define ll long long

int help(vector<int>& v, int n, vector<int>& dp){
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];

    int t = v[n] + help(v, n-2, dp);
    int nt = help(v, n-1, dp);

    return dp[n] = max(t, nt);
}

int main(){
    vector<int> v = {2,7,9,3,1};
    int n = v.size();
    vector<int> dp(n+1, -1);

    cout << help(v, n-1, dp);
}