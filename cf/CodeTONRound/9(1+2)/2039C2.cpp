#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x, m;
    cin >> x >> m;

    ll ans = 0;
    ll p = min(m, 1ll << __lg(x) << 2);

    for (ll i = 1; i <= p; i++) {
        ll res = (x ^ i);
        if (res % i == 0 && res % x != 0) {
            ans++;
        }
    }
    // cerr << ans << "\n";

    vector<int> pos;
    for (int i = 0; i < 60; i++) {
        if ((1ll << i) & m) pos.push_back(i);
    }
    reverse(pos.begin(), pos.end());

    ll lef = 0;
    ll sum = 0;

    int ok = 1;
    for (int i = 0; i < pos.size(); i++) {
        if ((1ll << pos[i]) <= x) break;
        ll now = (1ll << pos[i]) - 1;
        ans += (now + lef) / x + 1;
        if (lef > 0) ans -= (lef - 1) / x + 1;
        ans -= ok;
        ok = 0;
        lef = (lef + (1ll << pos[i])) % x;
        sum += (1ll << pos[i]);
        // cerr << ans << "\n";
    }
    // cerr << sum << "\n";

    for (ll i = max(sum, 1LL); i <= m; i++) {
        if ((i ^ x) % x == 0) ans++;
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