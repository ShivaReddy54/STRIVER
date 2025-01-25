#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()){
            left.push(num);
            return;
        }
        
        if(num > left.top()) right.push(num);
        else left.push(num);

        balance();
    }

    void balance(){
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
        else{
            if(right.size() < left.size() - 1){
                right.push(left.top());
                left.pop();
            }
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()) return left.top();
        else{
            double ans = left.top() + right.top();
            ans = ans / 2;
            
            return ans;
        }
    }
};

