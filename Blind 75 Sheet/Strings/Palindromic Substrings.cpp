#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool pal(string& s){
    int l = 0, r = s.size()-1;

    while(l < r){
        if(s[l] != s[r]) return 0;
        l++; r--;
    }
    return 1;
}

int main() {
    string s = "abc";
    int ans = 0;

    for(int i=0; i<s.size(); i++){
        string t = ""; t += s[i];
        for(int j=i+1; j<s.size(); j++){
            t += s[j];
            ans += pal(t);
        }
    }
    cout << ans + s.size();
}