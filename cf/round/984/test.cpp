#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll r = 1;
    while (1) {
        if (r < a) r <<= 1;
        else break;
    }
    cerr << r << "\n";
    ll p = a ^ b ^ 0;
    cout << p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}