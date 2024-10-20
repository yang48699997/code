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

template<class T> 
struct Fenwick {
    int n;
    vector<T> a;
    Fenwick(int x) : n(x), a(x + 1) {};
    void build() {
        for (int i = 1; i <= n; i++) {
            int nxt = i + (i & -i);
            if (nxt <= n) a[nxt] += a[i];
        }
    }
    T query(int x) {
        T res = 0;
        while (x) {
            res += a[x];
            x -= (x & -x);
        }
        return res;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void update(int x, T val) {
        while (x <= n) {
            a[x] += val;
            x += (x & -x);
        }
        return;
    }
};

using F = Fenwick<ll>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    F t(n);
    DSU dsu(n + 2);
    vector<int> v(n + 2);
    ll ans = 0;
    int pre = 0;
    for (int i = n - 1; i >= 0; i--) {
        int now = t.query(a[i]);
        ans += max(0, pre - now);
        t.update(a[i], 1);
        v[a[i]] = 1;
        if (v[dsu.find(a[i] - 1)]) {
            t.update(a[i], -1);
            dsu.merge(dsu.find(a[i] - 1), a[i]);
        }
        if (v[dsu.find(a[i] + 1)]) {
            t.update(dsu.find(a[i] + 1), -1);
            dsu.merge(a[i], dsu.find(a[i] + 1));
        }
        pre = now;
    }
    ans += pre;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}