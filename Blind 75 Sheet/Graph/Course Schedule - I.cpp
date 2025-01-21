#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main() {
    int n = 2; vector<vector<int>> pre = {{1, 0}};

    vector<int> adj[n], in(n);
    for(auto i : pre){
        adj[i[0]].push_back(i[1]);
        in[i[1]]++;
    }

    queue<int> q;
    for(int i=0; i<n; i++) if(in[i] == 0) q.push(i);

    int ans = 0;
    while(!q.empty()){
        int node = q.front(); q.pop(); ans++;

        for(auto i : adj[node]){
            in[i]--;
            if(in[i] == 0) q.push(i);
        }
    }

    cout << (ans == n);
}