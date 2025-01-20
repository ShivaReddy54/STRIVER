#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> v = {2,7,11,15};
    int tar = 9, n = v.size();

    // Brute force --> O(N^2)
    pair<int, int> ans;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(v[i] + v[j] == tar) {
                ans = {i, j};
                break;
            }
    cout << ans.first << " " << ans.second;

    
    // Better  --> O(NlogN)
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    while(l < r){
        int sum = v[l] + v[r];
        if(sum == tar){
            ans = {l, r};
            break;
        }

        if(sum > tar) r--;
        else l++;
    }
    cout << ans.first << " " << ans.second;

    
    // Optimal --> O(N)
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        int d = tar - v[i];

        if(mp.find(d) != mp.end()){
            ans = {mp[d], i};
            break;
        }
        mp[v[i]] = i;
    }
    cout << ans.first << " " << ans.second;

}