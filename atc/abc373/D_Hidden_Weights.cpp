#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU{
    vector<int> fa, sz;
    
    DSU(int n) : fa(n), sz(n, 1) {
        for ( int i = 0; i < n; i++) fa[i]=i;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if( x == y) return false;
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
    
    int size(int x) {
        x = find(x);
        return sz[x];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> e(n);
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int w;
        cin >> w;
        e[v].emplace_back(u, -w);
        e[u].emplace_back(v, w);
        dsu.merge(v, u);
    }
    vector<ll> ans(n);
    vector<int> v(n);
    auto dfs = [&](auto &&self, int x) -> void {
        for (auto [nxt, w] : e[x]) {
            if (v[nxt]) continue;
            ans[nxt] = ans[x] + w;
            v[nxt] = 1;
            self(self, nxt);
        }
    };
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) {
            v[i] = 1;
            dfs(dfs, i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}