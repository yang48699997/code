#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU{
    vector<int> fa, sz;
    vector<ll> sum;
    DSU(int n) : fa(n), sz(n, 1), sum(n) {
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
        sum[x] += sum[y];
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

    vector<ll> a(n);
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dsu.sum[i] = a[i];
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 2) {
            int l;
            cin >> l;
            l--;

            double p = dsu.sum[dsu.find(l)];
            p /= dsu.size(l);

            cout << fixed << setprecision(10) << p << "\n";
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            while (dsu.find(r) > l) {
                dsu.merge(dsu.find(r) - 1, r);
            }
        }
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}