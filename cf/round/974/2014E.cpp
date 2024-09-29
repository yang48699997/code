#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e18;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<pair<int, int>>> e(n * 2);
    vector<int> p(n);
    vector<int> v(n);
    for (int i = 0; i < h; i++) {
        cin >> p[i];
        p[i]--;
        v[p[i]] = 1;
        e[p[i]].emplace_back(p[i] + n, 0);
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
        e[v + n].emplace_back(u + n, w / 2);
        e[u + n].emplace_back(v + n, w / 2);
    }
    vector<ll> d1(n * 2, inf), d2(n * 2, inf);
    vector<int> v1(n * 2), v2(n * 2);
    d1[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [dis, x] = q.top();
        q.pop();
        if (v1[x]) continue;
        v1[x] = 1;
        for (auto [nxt, w] : e[x]) {
            if (v1[nxt]) continue;
            if (d1[nxt] > d1[x] + w) {
                d1[nxt] = d1[x] + w;
                q.push({d1[nxt], nxt});
            }
        }
    }
    d2[n - 1] = 0;
    q.push({0, n - 1});
    while (!q.empty()) {
        auto [dis, x] = q.top();
        q.pop();
        if (v2[x]) continue;
        v2[x] = 1;
        for (auto [nxt, w] : e[x]) {
            if (v2[nxt]) continue;
            if (d2[nxt] > d2[x] + w) {
                d2[nxt] = d2[x] + w;
                q.push({d2[nxt], nxt});
            }
        }
    }
    ll ans = inf;
    for (int i = 0; i < n; i++) {
        ans = min(ans, max(min(d1[i], d1[i + n]), min(d2[i], d2[i + n])));
    }
    if (ans == inf) cout << "-1\n";
    else cout << ans << "\n";
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