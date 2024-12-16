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
    int n;
    cin >> n;
    DSU dsu(n);

    vector<int> cnt(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = i;
        cnt[c[i]]++;
    }

    int q;
    cin >> q;

    while (q--) {
        int op;
        cin >> op;
        
        if (op == 1) {
            int x, p;
            cin >> x >> p;
            x--;
            p--;

            int l = dsu.find(x);
            int r = l + dsu.size(x) - 1;

            cnt[c[l]] -= r - l + 1;
            cnt[p] += r - l + 1;
            c[l] = c[r] = p;

            if (l > 0 && c[l - 1] == c[l]) dsu.merge(l - 1, l);
            if (r < n - 1 && c[r + 1] == c[r]) dsu.merge(r, r + 1);
        } else {
            int p;
            cin >> p;
            p--;

            cout << cnt[p] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}