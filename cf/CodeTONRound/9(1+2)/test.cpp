#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x, m;
    cin >> x >> m;
    ll ans = 0;

    for (ll i = 1; i <= m; i++) {
        ll p = (i ^ x);
        if (p % i == 0 || p % x == 0) ans++;
    }

    vector<int> pos;
    for (int i = 0; i < 60; i++) {
        if ((1ll << i) & m) pos.push_back(i);
    }
    reverse(pos.begin(), pos.end());

    ll sum = 0;
    ll cnt = 0;
    for (int i = 0; i < pos.size(); i++) {
        cerr << max(sum, 1LL) << " " << sum + (1ll << pos[i]) << "\n";
        for (ll j = max(sum, 1LL); j < sum + (1ll << pos[i]); j++) {
            ll p = (j ^ x);
            if (p % x == 0) cnt++;
        }
        cerr << cnt << "\n";
        sum += (1ll << pos[i]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}