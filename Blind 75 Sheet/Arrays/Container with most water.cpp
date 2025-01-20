#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    int ans = 0;


    // Better  --> O(N)
    // Two pointer
    int l = 0, r = v.size() - 1;
    while(l < r){
        int width = r - l;
        int height = min(v[l], v[r]);

        ans = max(ans, width * height);

        if(v[l] > v[r]) r--;
        else l++;
    }

    cout << ans;

}