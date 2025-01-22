#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<string> v = {"baa","abcd","abca","cab","cad"};
    int k = 4, n = v.size();

    vector<int> adj[k], in(k);
    for(int i=1; i<n; i++){
        string a = v[i-1], b = v[i];
        int len = min(a.size(), b.size());

        for(int j=0; j<len; j++){
            if(a[j] != b[j]){
                adj[a[j]-'a'].push_back(b[j]-'a');
                in[b[j]-'a']++;
                break;
            }
        }
    }

    queue<int> q;
    for(int i=0; i<k; i++) if(in[i] == 0) q.push(i);
    vector<int> ans;

    while(!q.empty()){
        int node = q.front(); q.pop();
        ans.push_back(node);

        for(auto i : adj[node]){
            in[i]--;
            if(in[i] == 0) q.push(i);
        }
    }

    for(auto i : ans) cout << char(i + 'a') << " ";


}