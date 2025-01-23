#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool dfs(vector<string>& v, vector<vector<bool>>& vis, int i, int j, int n, int m, int k, string& s) {
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || v[i][j] != s[k]) return 0;
    if (k == s.size() - 1) return 1;

    vis[i][j] = 1;
    for (int z = 0; z < 4; z++) {
        int r = i + dx[z];
        int c = j + dy[z];

        if (dfs(v, vis, r, c, n, m, k + 1, s)) return 1;
    }
    vis[i][j] = 0;
    return 0;
}

int main() {
    vector<string> v = {"ABCD", "SFCS", "ADEE"};
    string s = "ABCCED";

    int n = v.size(), m = v[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    bool ans = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == s[0])
                if (dfs(v, vis, i, j, n, m, 0, s)) ans = true;

    cout << ans;
}
