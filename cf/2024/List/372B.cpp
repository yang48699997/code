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
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int N = n * (n + 1) / 2;

    vector<vector<ll>> pre(N, vector<ll> (m + 1));
    vector<DSU> dsu(N, DSU(m + 1));

    int now = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int pok = 0;
            int p = j - i + 1;
            p = 1;
            for (int q = 0; q < m; q++) {
                int ok = 1;
                for (int k = i; k <= j; k++) {
                    if (s[k][q] == '1') ok = 0;
                }
                if (ok && pok) dsu[now].merge(q, q + 1);
                int pp = dsu[now].size(q + 1) - 1 + ok;
                if (!ok) dsu[now].sz[q + 1]--;
                pre[now][q + 1] = pre[now][dsu[now].find(q + 1) - 1] + p * pp * (pp + 1) / 2;
                pok = ok;
            }
            now++;
        }
    }

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;

        now = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                now++;
                if (a > i || a > j || c < i || c < j) {
                    continue;
                }

                int p = j - i + 1;
                p = p * (p + 1) / 2;
                p = 1;

                int f1 = dsu[now].find(b);
                int f2 = dsu[now].find(d);

                if (f1 == f2) {
                    if (dsu[now].size(f1)) ans += p * (d - b + 1) * (d - b + 2) / 2;
                } else {
                    ans += pre[now][d] - pre[now][f1 - 1];
                    if (f1 < b) {
                        int p1 = b - f1;
                        int p2 = dsu[now].size(b);
                        p1 = p2 - p1;
                        ans -= p2 * (p2 + 1) / 2 - p1 * (p1 + 1) / 2;
                    }
                }
            }
        }

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}