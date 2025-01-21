#include <bits/stdc++.h>
using namespace std;
#define ll long long

int help(string& a, string& b, int i, int j, vector<vector<int>>& dp){
    if(i < 0 or j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(a[i] == b[j]) return 1 + help(a, b, i-1, j-1, dp);
    else return max(help(a, b, i-1, j, dp), help(a, b, i, j-1, dp));
}

int main(){
    string a = "abcde", b = "ace";
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout << help(a, b, n-1, m-1, dp);
}