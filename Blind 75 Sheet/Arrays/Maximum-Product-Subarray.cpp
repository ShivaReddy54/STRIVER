#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> v = {2,3,-2,4};
    int n = v.size(), ans = 0;

    // Better  --> O(N^2)
    for(int i=0; i<n; i++){
        int p = 1;
        for(int j=i; j<n; j++){
            p *= v[j];
            ans = max(ans, p);
        }
    }
    cout << ans;

    // Optimal  --> O(N)
    ans = 0;
    int pre = 1, suf = 1;
    for(int i=0; i<n; i++){
        pre = max(1, pre * v[i]);
        suf = max(1, suf * v[n-i-1]);
        ans = max({ans, pre, suf});
    }
    cout << ans;
}