#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> v = {4,5,6,7,0,1,2};
    int n = v.size(), tar = 0;


    // Brute force  --> O(N)
    for(auto i : v) if(i == tar) return 1;
    return 0;

    
    // Optimal  --> O(logN)
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;

        if(v[mid] == tar) return 1;
        if(v[l] <= v[mid]){
            if(tar >= v[l] and tar <= v[mid]) r = mid - 1;
            else l = mid + 1;
        }
        else {
            if(tar >= v[mid] and tar <=v[r]) l = mid + 1;
            else r = mid - 1;
        }
    }
    return 0;


}