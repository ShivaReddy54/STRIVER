#include <bits/stdc++.h>
using namespace std;

// Memoisation
bool help(vector<int>& v, int i, vector<bool>& dp){
    if(i >= v.size()-1) return 1;
    if(v[i] == 0) return 0;
    if(dp[i]) return 1;

    for(int j=v[i]; j>=1; j--)
        if(help(v, i+j, dp)) return dp[i] = 1;
    return dp[i] = 0;
}

int main() {
    vector<int> v = {2,3,1,1,4};
    int n = v.size();

    vector<bool> dp(n+1, 0);
    cout << help(v, 0, dp);

    // Tabulation
    int far = 0, curr = 0;
    for(int i=0; i<n; i++){
        far = max(far, i + v[i]);

        if(curr == i) curr = far;
    }

    if(curr < n-1) cout << 0;
    else cout << 1;
}
