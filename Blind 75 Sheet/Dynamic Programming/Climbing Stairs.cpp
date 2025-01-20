#include <bits/stdc++.h>
using namespace std;
#define ll long long

int help(int n, vector<int>& dp){
    if(n <= 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = help(n-1, dp) + help(n-2, dp);
}

int main() {
    int n = 2;
    vector<int> dp(n+1, -1);

    cout << help(n, dp);

}