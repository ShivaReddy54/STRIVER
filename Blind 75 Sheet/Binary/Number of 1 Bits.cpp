#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n = 2147483645;

    int ans = 0;
    for(int i=0; i<32; i++) ans += (n >> i) & 1;
    cout << ans;
}