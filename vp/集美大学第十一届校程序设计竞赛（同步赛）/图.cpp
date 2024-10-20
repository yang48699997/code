#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 998244353;

struct DSU{
    vector<int> fa, sz;
    DSU(int n) : fa(n), sz(n, 1) {
        for (int i = 0; i < n; i++) fa[i]=i;
    }
    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> fa(n, vector<int> (20, -1));
    ll ans = 0;
    DSU dsu(n);
    vector<vector<int>> e(n);
    vector<int> d(n);

    auto dfs = [&](auto &&self, int x, int f) -> void {
        d[x] = d[f] + 1;
        fa[x][0] = f;
        for (int i = 1; i < 20; i++) {
            if (fa[x][i - 1] == -1) fa[x][i] = -1;
            else fa[x][i] = fa[fa[x][i - 1]][i - 1];
        }
        for (int nxt : e[x]) {
            if (nxt == f) continue;
            self(self, nxt, x);
        }
    };

    while (q--) {
        ll a, b, c;
        cin >> a >> b >> c;
        int opt = a * (2 + ans) % mod % 2;
        int u = b * (2 + ans) % mod % n;
        int v = c * (2 + ans) % mod % n;
        if (opt == 0) {
            if (dsu.size(u) > dsu.size(v)) swap(u, v);
            dsu.merge(u, v);
            e[v].push_back(u);
            e[u].push_back(v);
            dfs(dfs, u, v);
        } else {
            if (!dsu.same(u, v)) {
                ans = -1;
                cout << "-1\n";
                continue;
            }
            if (d[u] < d[v]) swap(u, v);
            ans = d[u] + d[v];
            int dif = d[u] - d[v];
            for (int i = 0; i < 20; i++) {
                if (1 << i & dif) {
                    u = fa[u][i];
                }
            }
            if (u == v) {
                ans -= 2 * d[u];
                cout << ans << "\n";
                continue;
            }
            for (int i = 19; i >= 0; i--) {
                if (fa[u][i] != fa[v][i]) {
                    u = fa[u][i];
                    v = fa[v][i];
                }
            }
            ans -= 2 * d[fa[u][0]];
            cout << ans << "\n";
        } 

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}