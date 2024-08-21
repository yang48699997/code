#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> c(n + 1), v(n + 1);
    vector<vector<pair<int, int>>> f(n + 1);
    for (int i = 1; i <= n; i++) {
        int p, t;
        cin >> p >> t;
        if (p == 0) {
            v[i] = 1;
            c[i] = t;
            f[i].emplace_back(1, i);
        } else {
            for (int j = 0; j < t; j++) {
                int x, a;
                cin >> x >> a;
                f[i].emplace_back(x, a);
            }
        }
    }

    int ok = 2;
    vector<ll> cnt(n + 1);
    ll mx = 0;
    auto dfs = [&](auto &&self, int x, ll t) -> ll {
        if (!ok) return 0;
        if (t > inf) {
            return -1;
        }
        ll res = 0;
        if (v[x]) {
            cnt[x] += t;
            res += c[x] * t;
            if (res > inf) {
                return -1;
            }
            return res;
        }
        if (x != k) {
            for (auto [x, a] : f[x]) {
                ll p = self(self, a, t * x);
                if (p == -1) return -1;
                res += p;
                if (res > inf) {
                    res = 0;
                    return 0;
                }
            }
        } else{
            for (auto [x, a] : f[x]) {
                ll p = self(self, a, t * x);
                if (p == -1) {
                    ok--;
                    if (ok == 0) break;
                    else continue;
                }
                res += p;
                if (res > inf) {
                    ok--;
                    if (ok == 0) break;
                    res -= max(p, mx);
                    continue;
                }
                mx = max(mx, p);
            }
        }
        return res;
    };
    ll ans = dfs(dfs, k, 1);
    if (ok == 0) cout << "Impossible\n";
    if (ok == 1) {
        cout << ans << "\n";
    } else {
        if (ans - mx > inf) {
            cout << "Impossible\n";
        } else cout << ans - mx << "\n";
    }
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