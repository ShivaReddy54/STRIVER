#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    vector<vector<int>> v = {{1, 4}, {10,15}, {7,10}};
    sort(v.begin(), v.end());

    for(int i=1; i<v.size(); i++)
        if(v[i][0] < v[i-1][1]) return 0;
    return 1;
}