#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    ll xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;

    ll t = (xs - xt) * (xs - xt) + (ys - yt) * (ys - yt);
    for (int i = 0; i < n; i++) {
        ll x = p[i].first, y = p[i].second;
        ll cur = (x - xt) * (x - xt) + (y - yt) * (y - yt);
        if (t >= cur) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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