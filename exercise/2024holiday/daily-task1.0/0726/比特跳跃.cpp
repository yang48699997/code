#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;
int T;
void solve() {
    int n, m;
    cin >> n >> m;
    ll k;
    cin >> k;
    vector<vector<pair<int, ll>>> e(n + 1);
    for(int i = 0; i < m; i++) {
        int x, y;
        ll t;
        cin >> x >> y >> t;
        e[x].push_back({y, t});
        e[y].push_back({x, t});
    }
    vector<ll> d(n + 1, inf);
    vector<int> v(n + 1);
    d[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    for (int i = 2; i <= n; i++) {
        d[i] = (1 | i) * k;
        q.push({d[i], i});
    }
    q.push({0, 1});
    vector<int> vv(1 << 20);
    auto dfs = [&] (auto &&self, int i, ll p) -> void {
        if (i > n) return;
        if (vv[i]) return;
        d[i] = min(d[i], p + i * k);
        vv[i] = 1;
        for (int j = 0; j < 20; j++) {
            if (1 << j & i) continue;
            self(self, ((1 << j) | i), p);
        }
    };
    while (!q.empty()) {
        ll dis = q.top().first;
        int x = q.top().second;
        q.pop();
        v[x] = 1;
        dfs(dfs, x, dis);
        for (auto &ed : e[x]) {
            int nxt = ed.first;
            ll dn = ed.second;
            if (v[nxt]) continue;
            ll dd = dis + dn;
            if (dd >= d[nxt]) continue;
            else {
                d[nxt] = dd;
                q.push({dd, nxt});
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << d[i] << " \n"[i == n];
    }
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