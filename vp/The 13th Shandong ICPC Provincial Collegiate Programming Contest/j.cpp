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
    int n, m, q;
    ll V;
    cin >> n >> m >> q >> V;

    vector<ll> val(m);
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v >> val[i];
        u--;
        v--;
        e[i] = {u, v};
    }

    vector<pair<int, int>> ask;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ask.emplace_back(u, v);
    }

    vector<int> ans(q);

    ll mask = 0;
    for (int i = 60; i >= 0; i--) {
        DSU dsu(n);
        if (1LL << i & V) {
            mask |= 1LL << i;
            continue;
        }
        for (int j = 0; j < m; j++) {
            if ((val[j] & mask) != mask) continue;
            if (1LL << i & val[j]) {
                dsu.merge(e[j].first, e[j].second);
            } else if (mask == V) {
                dsu.merge(e[j].first, e[j].second);
            }
        }
        for (int j = 0; j < q; j++) {
            if (dsu.find(ask[j].first) == dsu.find(ask[j].second)) ans[j] = 1;
        }
    }

    DSU dsu(n);
    for (int j = 0; j < m; j++) {
        if ((val[j] & mask) != mask) continue;
        dsu.merge(e[j].first, e[j].second);
    }

    for (int j = 0; j < q; j++) {
        if (dsu.find(ask[j].first) == dsu.find(ask[j].second)) ans[j] = 1;
    }
    for (int i = 0; i < q; i++) {
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