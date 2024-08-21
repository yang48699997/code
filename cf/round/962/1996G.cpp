#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int T;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> f(n + 1);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ll p = rng();
        f[x] ^= p;
        f[y] ^= p;
    }

    map<ll, int> cnt;
    for (int i = 0; i < n; i++) {
        f[i + 1] ^= f[i];
        ans = max(ans, ++cnt[f[i + 1]]);
    }

    ans = n - ans;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}