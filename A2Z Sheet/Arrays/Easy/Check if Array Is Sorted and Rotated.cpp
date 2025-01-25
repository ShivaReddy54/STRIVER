#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        if(nums[0] < nums.back()) cnt++;

        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]) cnt++;
            if(cnt > 1) return 0;
        }
        
        return 1;
    }
};