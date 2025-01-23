#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s = "anagram", t = "nagaram";
    vector<int> v(26);

    for(auto i : s) v[i-'a']++;
    for(auto i : t) v[i-'a']--;
    for(auto i : v) if(i != 0) return 0;
    return 1;
}