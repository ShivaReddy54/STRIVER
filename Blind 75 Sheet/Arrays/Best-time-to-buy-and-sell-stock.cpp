#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> v = {7, 1, 5, 3, 6, 4};
    int n = v.size();


    // O(N)
    int ans = 0, mini = v[0];
    for(int i=1; i<n; i++){
        ans = max(ans, v[i] - mini);
        mini = min(mini, v[i]);
    }
    cout << ans;
}