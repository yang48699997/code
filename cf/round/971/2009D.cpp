#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> c(n + 1);
    vector<ll> r(2);
    vector<vector<int>> v(n + 1, vector<int> (2));
    ll ans = 0;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        c[x]++;
        r[y]++;
        p.emplace_back(x, y);
        v[x][y] = 1;
    }
    for (auto [x, y] : p) {
        ans += (c[x] - 1) * (r[y] -  1);
        if (x > 0 && x < n && v[x + 1][y ^ 1] && v[x - 1][y ^ 1]) ans++;
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