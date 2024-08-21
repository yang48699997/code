#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    ll t0, t1, t2;
    cin >> t0 >> t1 >> t2;
    vector<int> l1(m), l2(m);
    vector<vector<int>> e(n);
    vector<int> adj(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y >> l1[i] >> l2[i];
        x--;
        y--;
        adj[i] = x ^ y;
        e[x].push_back(i);
        e[y].push_back(i);
    }

    const ll inf = 1e18;
    auto check = [&](int x) -> bool {
        vector<ll> d(n, inf);
        d[0] = x;
        vector<int> v(n);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
        q.push({x, 0});
        while (!q.empty()) {
            auto [dis, y] = q.top();
            q.pop();
            if (v[y]) continue;
            v[y] = 1;
            for (int p : e[y]) {
                int nxt = adj[p] ^ y;
                if (v[nxt]) continue;
                if (dis <= t1 && dis + l1[p] <= t1) {
                    if (dis + l1[p] < d[nxt]) {
                        d[nxt] = dis + l1[p];
                        q.push({d[nxt], nxt});
                    }
                } 
                ll now = max(t2, dis);
                if (now + l1[p] < d[nxt]) {
                    d[nxt] = now + l1[p];
                    q.push({d[nxt], nxt});
                }
                if (dis + l2[p] < d[nxt]) {
                    d[nxt] = dis + l2[p];
                    q.push({d[nxt], nxt});
                }
            }
        }
        return d[n - 1] <= t0;
    };

    int l = 0, r = t0;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1 << "\n";
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