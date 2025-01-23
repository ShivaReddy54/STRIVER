#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n = 121;

    if(n < 0) return 0;
    int rev = 0, t = n;

    while(t){
        rev = rev * 10 + t % 10;
        t /= 10;
    }
    return rev == n;
}