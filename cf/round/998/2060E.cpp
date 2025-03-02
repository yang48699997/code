#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU{
    vector<int> fa, sz;
    DSU(int n) : fa(n), sz(n, 1) {
        for (int i = 0; i < n; i++) fa[i] = i;
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
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<array<int, 2>> p(m1), p2(m2);
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        p[i] = {u, v};
    }

    DSU dsu2(n);
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        dsu2.merge(u, v);
        p2[i] = {u, v};
    }

    int ans = 0;
    DSU dsu1(n);
    for (int i = 0; i < m1; i++) {
        int u = p[i][0];
        int v = p[i][1];
        if (dsu2.same(u, v)) {
            dsu1.merge(u, v);
            continue;
        }
        ans++;
    }

    for (int i = 0; i < m2; i++) {
        int u = p2[i][0];
        int v = p2[i][1];
        if (!dsu1.same(u, v)) {
            ans++;
            dsu1.merge(u, v);
        }
    }

    cout << ans << "\n";
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