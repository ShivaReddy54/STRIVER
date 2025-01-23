#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<vector<int>> v = {{1,2,3}, {4,5,6}, {7,8,9}};
    int n = v.size(), m = v[0].size();

    // Transpose
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++) swap(v[i][j], v[j][i]);
    
    // Reverse
    for(int i=0; i<n; i++) reverse(v[i].begin(), v[i].end());

    for(auto i : v){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
}
