#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Memoisation
int help(vector<int>& v, int i, int prev, vector<vector<int>>& dp){
    if(i == v.size()) return 0;
    if(dp[i][prev+1] != -1) return dp[i][prev+1];

    int nt = help(v, i+1, i, dp);
    int t = 0;
    if(prev == -1 or v[i] > v[prev])
        t = 1 + help(v, i+1, i, dp);

    return dp[i][prev+1] = max(t, nt);
}

int main(){
    vector<int> v = {10,9,2,5,3,7,101,18};
    int n = v.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    cout << help(v, 0, -1, dp);

}