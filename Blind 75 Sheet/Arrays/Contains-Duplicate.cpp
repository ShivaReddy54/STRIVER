#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> v = {1,2,3,1};

    // Brute Force  --> O(NlogN)
    sort(v.begin(), v.end());
    for(int i=1; i<v.size(); i++)
        if(v[i] == v[i-1]) return 1;
    return 0;

    // Better  --> O(N)
    unordered_set<int> st;
    for(auto i : v){
        if(st.count(i)) return 1;
        st.insert(i);
    }
}