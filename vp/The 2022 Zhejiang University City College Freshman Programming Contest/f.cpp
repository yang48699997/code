#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<ll> p;
    for (int i = 0; i < n; i++) {
        ll now = max(0LL, (b[i] * m - a[i] - 1) / c[i] + 1);
        p.emplace_back(now);
    }
    int ans = 0;
    ll now = 0;
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        if (now + p[i] <= k) {
            now += p[i];
            ans++;
        } else break;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}