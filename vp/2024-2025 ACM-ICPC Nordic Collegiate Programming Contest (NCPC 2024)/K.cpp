#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll p, n;
    cin >> n >> p;
    ll p1 = (n - p) / 2;
    ll l1 = p1 % p;
    ll l2 = p1 % p;
    if (l1 + l2 == p) {
        l1 -= p; 
    }

    cout << l1 + l2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}