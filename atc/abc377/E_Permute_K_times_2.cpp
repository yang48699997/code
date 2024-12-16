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
        if (x > y) swap(x, y);
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

ll powMod(ll x, ll y, int mod) {
    ll res = 1;
    while (y) {
        if(y & 1)res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    };
    return res;
};

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<int> p(n), ref(n);
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        ref[p[i]] = i;
        dsu.merge(i, p[i]);
    }

    vector<vector<int>> e(n);
    auto dfs = [&](auto &&self, int x, int t, int ok = 0) -> void {
        if (ok && t == x) return;
        e[t].push_back(x);
        self(self, p[x], t, 1);
    };

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) != i) continue;
        dfs(dfs, i, i);
        int d = powMod(2, k, dsu.size(i));
        d--;
        if (d == -1) d += dsu.size(i);
        for (int j = 0; j < e[i].size(); j++) {
            ans[ref[e[i][j]]] = e[i][(j + d) % dsu.size(i)];
        }
    }


    for (int i = 0; i < n; i++) cout << ans[i] + 1 << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}