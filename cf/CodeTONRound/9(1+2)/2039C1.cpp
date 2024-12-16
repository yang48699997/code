#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x, m;
    cin >> x >> m;

    int ans = 0;
    m = min(m, 1ll << __lg(x) << 2);
    for (ll i = 1; i <= m; i++) {
        if (i == x) continue;
        ll res = (x ^ i);
        if (x % res == 0 || i % res == 0) ans++;
    }

    cout << ans << "\n";
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