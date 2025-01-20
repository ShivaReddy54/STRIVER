#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int a = 14, b = 16;
    int ans = 0, carry = 0;

    for (int i = 0; i < 32; i++) {
        bool x = (a >> i) & 1;
        bool y = (b >> i) & 1;

        int sum = x + y + carry;
        if (sum == 1) {
            ans |= (1 << i);
            carry = 0;
        } else if (sum == 2)  carry = 1;
        else if (sum == 3) {
            ans |= (1 << i);
            carry = 1;
        }
    }

    cout << ans;
}
