#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    int n = v.size();
    int ans = 0;

    // Brute Force  --> O(N^2)
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += v[j];
            ans = max(ans, sum);
        }
    }
    cout << ans;

    // Optimal  --> O(N)
    // Kadanes Algorithm
    ans = 0;
    int curr = 0;
    for(auto i : v){
        curr = max(0, curr + i);
        ans = max(ans, curr);
    }
    cout << ans;
}