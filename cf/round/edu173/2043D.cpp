#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll l, r, g;
    cin >> l >> r >> g;

    ll L = -1, R = -1;
    
    l = (l - 1) / g + 1;
    r = r / g;

    if (l > r) {
        cout << L << " " << R << "\n";
        return;
    }

    for (ll len = r - l + 1; len > 0; len--) {
        for (ll i = l; i + len - 1 <= r; i++) {
            if (__gcd(i, i + len - 1) == 1) {
                L = i * g;
                R = (i + len - 1) * g;
                cout << L << " " << R << "\n";
                return;
            }
        }
    }

    cout << L << " " << R << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}