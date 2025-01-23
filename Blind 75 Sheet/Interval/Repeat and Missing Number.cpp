#include <bits/stdc++.h>
using namespace std;

// Time --> O(N)  Space --> O(N)
vector<int> repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> v(n+1, 0);
    
    for(auto i : A) v[i]++;
    
    vector<int> ans(2, -1);
    
    for(int i=1; i<=n; i++){
        if(v[i] == 0) ans[1] = i;
        if(v[i] > 1) ans[0] = i;
    }
    
    return ans;
}


// Time --> O(N)   Space  --> O(1)
vector<int> repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> v = A;
    
    for(int i=0; i<n; i++) v[i]--;
    
    for(int i=0; i<n; i++) v[v[i] % n] += n;
    
    vector<int> ans(2, -1);
    
    for(int i=0; i<n; i++){
        if(v[i] / n == 0) ans[1] = i+1;
        if(v[i] / n > 1) ans[0] = i + 1;
    }
    
    return ans;
}

