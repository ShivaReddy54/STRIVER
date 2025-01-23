#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string s = "ADOBECODEBANC", t = "ABC";
    int m = t.size();

    unordered_map<char, int> mp;
    for(auto i : t) mp[i]++;
    int maxi = INT_MAX, st = -1, l = 0;

    for(int r=0; r<s.size(); r++){
        mp[s[r]]--;
        if(mp[s[r]] >= 0) m--;

        while(m==0 and l <= r){
            if(maxi > r-l+1){
                maxi = r-l+1;
                st = l;
            }

            mp[s[l]]++;
            if(mp[s[l]] > 0) m++;
            l++;
        }
    }
    maxi == INT_MAX ? cout << "" : cout << s.substr(st, maxi);
}