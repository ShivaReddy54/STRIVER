#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Memoisation
int n;
int help(string& s, int i, vector<int>& dp){
    if(i == n) return 1;
    if(s[i] == '0') return 0;
    if(dp[i] != -1) return dp[i];

    int ans = help(s, i+1, dp);
    if (i < n - 1 and (s[i] == '1' or (stoi(s.substr(i, 2)) <= 26)))
        ans += help(s, i+2, dp);
    return dp[i] = ans;
}

 int main(){
    string s = "10"; n = s.size();
    // vector<int> dp(n+1, -1);
    // cout << help(s, 0, dp) << endl;

     // Tabulation
    string s = "27";
    int n = s.size();

    vector<vector<int>> dp(2, vector<int>(n, 0));
    if(s[0] != '0') dp[0][0] = 1;
    for(int i=1; i<n; i++){
        if(s[i] != '0') dp[0][i] = dp[0][i-1] + dp[1][i-1];
        if(s[i-1] != '0' and stoi(s.substr(i-1, 2)) <= 26) dp[1][i] = dp[0][i-1];
    }
    cout << dp[0].back() + dp[1].back();

    // Space optimization
    int a = 0, b = 0;
    if(s[0] != '0') a = 1;
    for(int i=1; i<n; i++){
        int ca = 0, cb = 0;

        if(s[i] != '0') ca = a + b;
        if(s[i-1] != '0' and stoi(s.substr(i-1, 2)) <= 26) cb = a;

        a = ca; b = cb;
    }
    cout << a + b;
 }