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
    string s;
    cin >> n >> s;

    DSU dsu(n);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '/') continue;
        if (s[i] == s[i + 1]) dsu.merge(i, i + 1);
    }

    int ans = s.back() == '/';
    for (int i = 0; i < n - 1; i++) {
        if (dsu.find(i) != i) continue;

        if (s[i] != '/') continue;
        
        if (i == 0) {
            ans = 1;
            continue;
        }

        int l = 0, r = 0;
        if (s[i - 1] == '1') {
            l = dsu.size(i - 1);
        }
        if (i + dsu.size(i) != n && s[i + dsu.size(i)] == '2') {
            r = dsu.size(i + dsu.size(i));
        }

        ans = max(ans, 1 + min(l, r) * 2);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}