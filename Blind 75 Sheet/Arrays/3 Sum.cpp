#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> v = {-1,0,1,2,-1,-4};
    int n = v.size();
    vector<vector<int>> ans;


    // Brute force  --> O(N^3)
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            for(int k=j+1; k<n; k++)
                if(v[i] + v[j] + v[k] == 0) ans.push_back({i, j, k});

    for(auto i : ans){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }


    // Optimal  --> O(N^2)
    sort(v.begin(), v.end());
    for(int i=0; i<n-2; i++){
        int l = i+1, r = n-1;
        while(l < r){
            int sum = v[i] + v[l] + v[r];

            if(sum == 0){
                ans.push_back({i, l, r});
                l++; r--;
            }
            else if(sum > 0) r--;
            else l++;
        }
    }

    for(auto i : ans){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
}