#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type, greater<int>,rb_tree_tag,tree_order_statistics_node_update> oset;

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
    int n, q;
    cin >> n >> q;

    vector<oset> st(n);
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        st[i].insert(i);
    }

    while (q--) {
        int c;
        cin >> c;

        if (c == 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;

            if (dsu.same(u, v)) continue;

            if (dsu.size(u) > dsu.size(v)) {
                swap(u, v);
            }

            for (auto x : st[dsu.find(u)]) {
                st[dsu.find(v)].insert(x);
            }

            st[dsu.find(u)].clear();

            dsu.merge(v, u);
        } else {
            int u, k;
            cin >> u >> k;
            u--;

            if (dsu.size(u) < k) cout << "-1\n";
            else cout << *st[dsu.find(u)].find_by_order(k - 1) + 1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}