#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s = "()[]{}";
    
    // Time  -->  O(N)   Space  --> O(N)
    stack<char> st;
    for(auto i : s){
        if(i == '(' or i == '[' or i == '{') st.push(i);
        else{
            if(st.empty()) return 0;

            if(i == ')' and st.top() != '(') return 0;
            if(i == ']' and st.top() != '[') return 0;
            if(i == '}' and st.top() != '{') return 0;
            st.pop();
        }
    }

    return st.empty();

    // Time  --> O(N)  Space  --> O(1)
    int cnt = 0;
    for(auto i : s){
        if(i == '(' or i == '[' or i == '{') cnt++;
        else cnt--;
    }
    return cnt == 0;
}