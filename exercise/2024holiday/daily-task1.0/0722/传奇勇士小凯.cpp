    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    int T;

    ll gcd(ll x, ll y) {
        while (y) {
            ll t = y;
            y = x % y;
            x = t;
        };
        return x;
    };

    void solve() {
        int n;
        cin >> n;
        vector<vector<int>> e(n);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<ll> p(n), q(n);
        auto dfs = [&](auto &&self, int x, int fa) -> void {
            p[x] = 15;
            q[x] = a[x];
            ll g = gcd(p[x], q[x]);
            p[x] /= g;
            q[x] /= g;
            ll mx1 = 0, mx2 = 1;
            for (int nxt : e[x]) {
                if (nxt == fa) continue;
                self(self, nxt, x);
                if (mx1 * q[nxt] < mx2 * p[nxt]) {
                    mx1 = p[nxt];
                    mx2 = q[nxt];
                }
            } 
            ll res1 = p[x] * mx2 + mx1 * q[x]; 
            ll res2 = mx2 * q[x]; 
            g = gcd(res1, res2);
            res1 /= g; 
            res2 /= g; 
            p[x] = res1;
            q[x] = res2;
        };

        dfs(dfs, 0, -1);
        cout << p[0] << "/" << q[0] << "\n";
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