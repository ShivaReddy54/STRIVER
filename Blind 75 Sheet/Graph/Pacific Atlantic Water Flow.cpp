#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n, m;
    void dfs(int i, int j, int prev, vector<vector<int>>& heights, vector<vector<bool>>& vis){
        if(i<0 or i>=n or j<0 or j>=m or vis[i][j] or heights[i][j] < prev) return;

        vis[i][j] = 1;

        // up
        dfs(i-1, j, heights[i][j], heights, vis);
        // down
        dfs(i+1, j, heights[i][j], heights, vis);
        // left
        dfs(i, j-1, heights[i][j], heights, vis);
        // right
        dfs(i, j+1, heights[i][j], heights, vis);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<bool>> a(n, vector<bool>(m, 0)), b(n, vector<bool>(m));

        // first row and col
        for(int i=0; i<m; i++) dfs(0, i, -1,  heights, a);
        for(int i=0; i<n; i++) dfs(i, 0, -1, heights, a);

        // bottom row and col
        for(int i=0; i<m; i++) dfs(n-1, i, -1, heights, b);
        for(int i=0; i<n; i++) dfs(i, m-1, -1, heights, b);

        vector<vector<int>> ans;

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(a[i][j] and b[i][j]) ans.push_back({i, j});
            
        sort(ans.begin(), ans.end());

        return ans;

    }
};