#include <bits/stdc++.h>
using namespace std;
#define ll long long

void help(string& s){
    int ans = 0, l = 0;
    unordered_set<char> st;
    for(int r=0; r<s.size(); r++){
        while(l<r and  st.find(s[r]) != st.end()){
            st.erase(s[l]); l++;
        }
        st.insert(s[r]);
        ans = max(ans, r-l+1);
    }
}

int main(){
    string s = "abcabcbb";
    int ans = 0;

    // Time  --> O(N^2)
    for(int i=0; i<s.size(); i++){
        unordered_set<char> st;
        int curr = 0;

        for(int j=i; j<s.size(); j++){
            if(!st.count(s[j])){
                curr++;
                st.insert(s[j]);
            }
            else break;
        }
        ans = max(ans, curr);

    }

    cout << ans;

}