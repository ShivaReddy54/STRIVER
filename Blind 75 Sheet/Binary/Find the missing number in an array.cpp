#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<int> v = {3,0,1};
    int n = v.size();

    // Brute force  --> O(N)
    int tot = (n * (n + 1)) >> 1;
    int sum = 0;
    for(auto i : v) sum += i;
    cout << tot - sum;
}