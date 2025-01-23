    #include <bits/stdc++.h>
using namespace std;
#define ll long long

string encode(vector<string>& s) {
    string ans;
    for(auto i : s){
        ans += i ;
        ans += '#';
    }
    ans.pop_back();
    return ans;
}

vector<string> decode(string& s) {
    vector<string> ans;
    string t;

    for(auto i : s){
        if(i != '#') t += i;
        else{
            ans.push_back(t);
            t = "";
        }
    }
    if(t.size() > 0) ans.push_back(t);
    return ans;
}