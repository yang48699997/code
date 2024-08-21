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
    int t = m / (n - 1);
    vector<DSU> dsu(t, n);
    vector<int> ans(m, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int l = 0, r = t - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (dsu[mid].find(x) == dsu[mid].find(y)) l = mid + 1;
            else r = mid - 1;
        }
        // cerr << l << "\n";
        if (l >= t) continue;
        else dsu[l].merge(x, y), ans[i] = l;
    }

    for (int i = 0; i < m; i++) {
        if (ans[i] == -1) cout << ans[i] << " \n"[i == m - 1];
        else if (dsu[ans[i]].size(0) != n) cout << -1 << " \n"[i == m - 1];
        else cout << ans[i] + 1 << " \n"[i == m - 1];
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