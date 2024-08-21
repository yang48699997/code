#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct DSU{
    vector<int> fa, size;
    
    DSU(int n) : fa(n), size(n, 1) {
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
        size[x] += size[y];
        fa[y] = x;
        return true;
    }
    
    int getCount(int x) {
        x = find(x);
        return size[x];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    vector<int> deg(n);

    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
        deg[x]++;
        deg[y]++;
        dsu.merge(x, y);
    }
    vector<int> pre(1);
    map<int, int> mp;
    vector<vector<int>> b(n);
    for (int i = 0; i < n; i++) {
        b[dsu.find(i)].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) != i) continue;
        mp[i] = pre.size();
        pre.push_back(pre.back());
        int sum = b[i].size();
        for (int nxt : b[i]) {
            if (deg[nxt] == 1) sum--;
        }
        if (sum <= 1) pre.back()++;
    }

    vector<int> ok(n, -1);
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        for (int nxt : e[i]) {
            if (deg[nxt] > 1) p[i].push_back(nxt);
        }
    }

    vector<int> ans;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int fa = dsu.find(i);
        int l = mp[fa];
        int sum = pre.back() - pre[l] + pre[l - 1];
        if (sum != pre.size() - 2) continue;
        v[i] = 1;
        for (int nxt : e[i]) {
            deg[nxt]--;
            if (deg[nxt] == 1) v[nxt] = 1;
        }

        int mask = 1;
        for (int nxt : e[i]) {
            if (p[nxt].size() == 0) continue;
            if (ok[nxt] == 1) continue;
            else if (ok[nxt] == -1) {
                int res = 1;
                for (int q : p[nxt]) {
                    if (!v[q]) {
                        res = 0;
                        break;
                    }
                }
                ok[nxt] = res;
            }
            if (!ok[nxt]) {
                if (deg[nxt] == 1) {
                    int a = -1;
                    for (int np : e[nxt]) {
                        if (np == i) continue;
                        else a = np;
                    }
                    if (ok[a] != -1) mask &= ok[a];
                    else {
                        ok[a] = 1;
                        for (int q : p[a]) {
                            if (!v[q]) {
                                ok[a] = 0;
                                break;
                            }
                        }
                        mask &= ok[a]; 
                    }
                } else mask = 0;
            }
            // cerr << ok[nxt] << "\n";
            if (!mask) break;
        }
        if (mask) ans.push_back(i + 1);

        for (int nxt : e[i]) {
            if (deg[nxt] == 1) {
                int a = -1;
                for (int np : e[nxt]) {
                    if (np == i) continue;
                    else a = np;
                }
                ok[a] = -1;
            }
            deg[nxt]++;
            ok[nxt] = -1;   
            v[nxt] = 0;
        }
        v[i] = 0;
    }

    if (ans.size() == 0) cout << "-1\n";
    else {
        for (int i : ans) cout << i << " \n"[i == ans.back()];
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