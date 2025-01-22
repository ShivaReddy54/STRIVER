#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    int n = nums.size();
    if(n <= 0) return 0;

    int ans = 1, curr =0, mini = INT_MIN;

    // Better  --> O(NlogN)
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++){
        if(nums[i] - 1 == mini){
            curr++;
            mini = nums[i];
        }else if(nums[i] != mini){
            curr = 1;
            mini = nums[i];
        }

        ans = max(ans, curr);
    }
    return ans;


    // Optimal --> O(N)
    int ans = 1;
    unordered_set<int> st(nums.begin(), nums.end());

    for(auto i : st){
        if(st.find(i-1) == st.end()){
            int c = i, cnt = 0;
            while(st.find(c) != st.end()){
                c++; cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;
}