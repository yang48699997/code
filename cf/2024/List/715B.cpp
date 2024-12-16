#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, L, s, t;
    cin >> n >> m >> L >> s >> t;

    vector<vector<array<int, 2>>> e(n);
    vector<array<int, 3>> pend;
    vector<array<int, 3>> ans(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 0) pend.push_back({u, v, i});
        else {
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        ans[i] = {u, v, w};
    }

    vector<ll> dis(n);
    vector<int> v(n);
    const ll inf = 1e18;
    auto check = [&]() -> ll {
        dis.assign(n, inf);
        v.assign(n, 0);
        dis[s] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
        q.push({0, s});
        
        while (!q.empty()) {
            auto [d, x] = q.top();
            q.pop();
            if (v[x]) continue;
            v[x] = 1;
            for (auto &adj : e[x]) {
                int nxt = adj[0];
                int w = adj[1];
                if (v[nxt] || w + dis[x] >= dis[nxt]) continue;
                dis[nxt] = dis[x] + w;
                q.push({dis[nxt], nxt});
            }
        }

        return dis[t];
    };

    int l = 1, r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        
        for (auto p : pend) {
            int u = p[0], v = p[1], i = p[2];
            e[u].push_back({v, mid});
            e[v].push_back({u, mid});
        }

        ll p = check();
        if (p >= L) r = mid - 1;
        else l = mid + 1;

        for (auto p : pend) {
            int u = p[0], v = p[1], i = p[2];
            e[u].pop_back();
            e[v].pop_back();
        }
    }

    int cl = 0, cr = pend.size();

    while (cl <= cr) {
        int cnt = 0;
        int mid = (cl + cr) / 2;
        for (auto p : pend) {
            cnt++;
            int u = p[0], v = p[1], i = p[2];
            if (cnt <= mid) {
                e[u].push_back({v, r});
                e[v].push_back({u, r});
                ans[i][2] = r;
            } else {
                e[u].push_back({v, r + 1});
                e[v].push_back({u, r + 1});
                ans[i][2] = r + 1;
            }
        }

        if (check() > L) cl = mid + 1;
        else cr = mid - 1;

        for (auto p : pend) {
            int u = p[0], v = p[1], i = p[2];
            e[u].pop_back();
            e[v].pop_back();
        }
    }

    int cnt = 0;
    for (auto p : pend) {
        cnt++;
        int u = p[0], v = p[1], i = p[2];
        if (cnt <= cl) {
            e[u].push_back({v, r});
            e[v].push_back({u, r});
            ans[i][2] = r;
        } else {
            e[u].push_back({v, r + 1});
            e[v].push_back({u, r + 1});
            ans[i][2] = r + 1;
        }
    }

    if (check() != L || (r == 0 && cl != 0)) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < m; i++) {
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}