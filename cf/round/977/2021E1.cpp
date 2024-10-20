#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve() {
    int n, m, p;
    std::cin >> n >> m >> p;
    
    std::vector<int> s(p);
    for (int i = 0; i < p; i++) {
        std::cin >> s[i];
        s[i]--;
    }
    
    std::vector<std::array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = {w, u, v};
    }
    
    std::sort(edges.begin(), edges.end());
    
    DSU dsu(2 * n - 1);
    
    int cnt = n;
    
    std::vector<int> W(2 * n - 1);
    std::vector<std::vector<int>> adj(2 * n - 1);
    for (auto [w, u, v] : edges) {
        if (!dsu.same(u, v)) {
            int x = cnt++;
            W[x] = w;
            adj[x].push_back(dsu.find(v));
            adj[x].push_back(dsu.find(u));
            dsu.merge(x, u);
            dsu.merge(x, v);
        }
    }
    
    std::vector<int> siz(2 * n - 1);
    for (auto x : s) {
        siz[x]++;
    }
    
    std::vector<i64> a;
    auto dfs = [&](auto &self, int x, int p = -1) -> i64 {
        i64 v = 0;
        for (auto y : adj[x]) {
            i64 w = self(self, y, x);
            siz[x] += siz[y];
            if (w > v) {
                std::swap(v, w);
            }
            a.push_back(w);
        }
        std::cerr << "dfs" << " " << x << "\n";
        if (p != -1) {
            v += 1LL * siz[x] * (W[p] - W[x]);
        }
        return v;
    };
    int rt = cnt - 1;
    a.push_back(dfs(dfs, rt));
    std::sort(a.rbegin(), a.rend());
    std::cerr << a.size();
    for (int i = 0; i < a.size(); i++) {
        std::cerr << a[i] << " \n"[i == a.size() - 1];
    }
    a.resize(n);
    
    i64 ans = 1LL * p * W[rt];
    for (int i = 0; i < n; i++) {
        ans -= a[i];
        std::cout << ans << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
