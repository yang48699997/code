#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll cal(ll x) {
    if (x == 0) return 1;
    if (x % 3 == 0) return cal(x / 3) + 1;
    else return cal(x - 1) + 1;
}

ll cal(ll l, ll r) {
    if (l == r) return cal(l);
    if (r % 3 != 2) {
        return max(cal(l, r - 1), cal(r));
    }
    if (l % 3 != 2) return cal(l + 1, r);
    return 3 + cal(l / 3, r / 3);
}

void solve() {
    ll l, r;
    cin >> l >> r;

    cout << cal(l, r) << "\n";
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