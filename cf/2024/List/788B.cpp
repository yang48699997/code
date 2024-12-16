#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
    int n, m;
    cin >> n >> m;
    vector<ll> cnt(n);
    DSU dsu(n);

    ll ans = 0;
    vector<int> vis(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        vis[u] = vis[v] = 1;
        if (u == v) {
            ans++;
            continue;
        }
        cnt[u]++;
        cnt[v]++;
        dsu.merge(u, v);
    }
    ans = ans * m - ans * (ans + 1) / 2;

    int p = find(vis.begin(), vis.end(), 1) - vis.begin();
    if (dsu.size(p) + count(vis.begin(), vis.end(), 0) != n) {
        cout << 0 << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}