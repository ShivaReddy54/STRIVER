#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<vector<int>> v = {{1,2,3}, {4,5,6}, {7,8,9}};
    int n = v.size(), m = v[0].size();

    int t = 0, b = m-1, l = 0, r = n-1;
    while(t<=b or l<=r){
        // l to r
        for(int i=l; i<=r; i++) cout << v[t][i] << " ";
        t++;

        // t to b
        for(int i=t; i<=b; i++) cout << v[i][r] << " ";
        r--;

        // r to l
        if(t <= b) {
            for (int i = r; i >= l; i--) cout << v[b][i] << " ";
            b--;
        }

        if(l <= r) {
            // b to t
            for (int i = b; i >=t; i--) cout << v[i][l] << " ";
            l++;
        }
    }

}
