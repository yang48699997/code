#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll l, r, k;
    cin >> l >> r >> k;
    map<pair<ll, ll>, ll> mp;

    auto dfs = [&](auto &&self, ll d, ll p) -> ll {
        // cerr << d << " " << p << "\n";
        if (d <= 0 || p < 0) return 0;
        if (d == 1) return 1;
        if (mp.count({d, p})) return mp[{d, p}];
        ll res = 1;
        ll mid = (d + 1) / 2;
        res += self(self, mid - 1, p - 1) + self(self, d - mid, p);
        mp[{d, p}] = res;
        return res;
    };

    // cerr << -1 << "\n";
    ll ans = dfs(dfs, r - l + 1, k);
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