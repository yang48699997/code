#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 2>>> E(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        mp[{u, v}] = i;
        E[u].push_back({v, c});
        E[v].push_back({u, c});
    }

    vector<int> v(n);
    vector<ll> dist(n, inf);
    vector<vector<int>> pre(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    dist[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [d, x] = q.top();
        q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (auto [nxt, c] : E[x]) {
            if (dist[nxt] < dist[x] + c) continue;
            else if (dist[nxt] == dist[x] + c) {
                pre[nxt].push_back(x);
            } else {
                pre[nxt].clear();
                pre[nxt].push_back(x);
                dist[nxt] = dist[x] + c;
                q.push({dist[nxt], nxt});
            }
        }
    }

    vector<vector<int>> e(n);
    v.assign(n, false);
    queue<int> q2;
    q2.push(n - 1);
    set<pair<int, int>> st;
    while (!q2.empty()) {
        int x = q2.front();
        q2.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (int nxt : pre[x]) {
            int nx = min(x, nxt);
            int ny = max(x, nxt);
            if (st.count({nx, ny})) continue;
            e[x].push_back(nxt);
            e[nxt].push_back(x);
            q2.push(nxt);
            st.insert({nx, ny});
        }
    }

    vector<int> ans(m);

    vector<int> dfn(n), low(n);
    int tot = 0;
    auto tarjan = [&](auto &&self, int x, int fa) -> void {
        dfn[x] = low[x] = ++tot;
        for (int nxt : e[x]) {
            if (!dfn[nxt]) {
                self(self, nxt, x);
                low[x] = min(low[x], low[nxt]);
                if (low[nxt] > dfn[x]) {
                    ans[mp[{min(nxt, x), max(nxt, x)}]] = 1;
                }
            } else if (nxt != fa) {
                low[x] = min(low[x], dfn[nxt]);
            }
        }
    };

    tarjan(tarjan, 0, 0);

    for (int i = 0; i < m; i++) {
        if (ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}