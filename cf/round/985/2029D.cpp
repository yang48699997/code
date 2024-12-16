#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> ans;
    vector<multiset<int>> e(n);
    
    auto update = [&](auto &&self, int x) -> void {
        int u = *e[x].begin();
        int v = *e[x].rbegin();
        cerr << x << " " << u << " " << v << "\n";
        ans.push_back({u, v, x});
        e[x].clear();
        e[u].erase(e[u].find(x));
        e[v].erase(e[v].find(x));
        if (e[u].find(v) == e[u].end()) {
            e[u].insert(v);
            e[v].insert(u);
        } else {
            e[u].erase(e[u].find(v));
            e[v].erase(e[v].find(u));
        }
        if (e[u].size() == 2) self(self, u);
        if (e[v].size() == 2) self(self, v);
    };

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (e[u].find(v) != e[u].end()) {
            e[u].erase(e[u].find(v));
            e[v].erase(e[v].find(u));
            continue;
        }
        e[u].insert(v);
        e[v].insert(u);
        if (e[u].size() == 2) {
            update(update, u);
        } else if (e[v].size() == 2) {
            update(update, v);
        }
    }

    vector<array<int, 2>> lef;
    vector<int> vv(n);
    int ok = 1;
    int u = -1, v = -1;
    for (int i = 0; i < n; i++) {
        if (vv[i]) continue;
        if (e[i].empty()) lef.push_back({i, i});
        else if (!ok) {
            vv[*e[i].begin()] = 1;
            lef.push_back({i, *e[i].begin()});
        } else {
            u = i;
            v = *e[i].begin();
            vv[v] = 1;
            ok = 0;
        }
    }

    if (!ok) {
        for (auto [x, y] : lef) {
            if (x == y) {
                ans.push_back({u, v, x});
                v = y;
            } else {
                ans.push_back({v, x, y});
            }
        }
    }
    
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p[0] + 1 << " " << p[1] + 1 << " " << p[2] + 1 << "\n";
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