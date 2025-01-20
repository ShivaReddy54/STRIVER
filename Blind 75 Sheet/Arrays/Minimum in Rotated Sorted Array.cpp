#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> v = {3,4,5,1,2};
    int n = v.size(), ans = INT_MAX;

    // Brute force  --> O(N)
    for(auto i : v) ans = min(ans, i);
    cout << ans;

    // Optimal  --> O(logN)
    // Binary Search
    int l = 0, r = n-1;
    ans = INT_MAX;
    while(l <= r){
        int mid = (l + r) / 2;

        if(v[mid] >= v[l]){
            ans = min(ans, v[l]);
            l = mid + 1;
        }
        else{
            ans = min(ans, v[mid]);
            r = mid - 1;
        }
    }
    cout << ans;
}