#include <bits/stdc++.h>
using namespace std;
#define ll long long

void help(vector<vector<int>>& v){
    int n = v.size(), m = v[0].size();
    
    // Space  --> O(1)
    bool r = false, c = false;
    for (int i = 0; i < m; i++) {
        if (v[0][i] == 0) {
            r = true;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (v[i][0] == 0) {
            c = true;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (v[i][j] == 0) {
                v[i][0] = 0;
                v[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
        if (v[i][0] == 0)
            for (int j = 1; j < m; j++) v[i][j] = 0;

    for (int j = 1; j < m; j++)
        if (v[0][j] == 0)
            for (int i = 1; i < n; i++) v[i][j] = 0;

    
    if (r) for (int i = 0; i < m; i++) v[0][i] = 0;
    if (c) for (int i = 0; i < n; i++) v[i][0] = 0;
    
    for (auto i : v) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
}

int main(){
    vector<vector<int>> v = {{1,1,1}, {1,0,1}, {1,1,1}};
    int n = v.size(), m = v[0].size();
    
    // Space  --> O(N)
    vector<pair<int, int>> z;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(v[i][j] == 0) z.push_back({i, j});

    for(auto i : z){
        int r = i.first, c = i.second;

        for(int j=0; j<n; j++) v[j][c] = 0; // row
        for(int j=0; j<m; j++) v[r][j] = 0; // col
    }

    for(auto i : v){
        for(auto j : i) cout << j << " ";
        cout << endl;   
    }

}
