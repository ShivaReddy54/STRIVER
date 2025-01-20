#include <bits/stdc++.h>
using namespace std;
#define ll long long

int help(int i, int j, int n, int m, vector<vector<bool>>& vis, vector<vector<int>>& dp){
    if(i == n-1 and j == m-1) return 1;
    if(i<0 or i>=n or j<0 or j>=m or vis[i][j]) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    vis[i][j] = 1;

    int r = help(i, j+1, n, m, vis, dp);
    int l = help(i+1, j, n, m, vis, dp);

    vis[i][j] = 0;

    return dp[i][j] = l + r;
}

int main(){
    int n = 3, m = 2;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    cout << help(0, 0, n, m, vis, dp);
}