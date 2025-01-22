#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dx[4] = {-1,1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int i, int j, int n, int m, vector<string>& v){
    if(i<0 or i>=n or j<0 or j>=m or v[i][j] == '0') return;

    v[i][j] = '0';

    for(int k=0; k<4; k++) dfs(i+dx[k], j+dy[k], n, m, v);
}

int main() {
    vector<string> v = {"11000", "11000", "00100", "00011"};;
    int n = v.size(), m = v[0].size();

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == '1'){
                dfs(i, j, n, m, v);
                ans++;
            }
        }
    }

    cout << ans;
}