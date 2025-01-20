#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> v = {1,2,3,4};
    int n = v.size(); vector<int> ans;


    // Brute force --> O(N^2)
    for(int i=0; i<n; i++){
        int p = 1;
        for(int j=0; j<n; j++) if(i != j) p *= v[j];
        ans.push_back(p);
    }
    for(auto i : ans) cout << i << " ";


    // Better  --> O(N)
    int curr = 1;
    for(int i=0; i<n; i++) {
        ans[i] = curr;
        curr *= v[i];
    }
    curr = 1;
    for(int i=n-1; i>=0; i--) {
        ans[i] = curr;
        curr *= v[i];
    }
    for(auto i : ans) cout << i << " ";


}