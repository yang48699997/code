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
    vector<vector<char>> g(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    if (g[0][m - 1] != '.' || (n * m - 1) % 3) {
        cout << "No\n";
        return;
    }
    DSU dsu(n * m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'U' && i > 0 && g[i - 1][j] == 'C') {
                dsu.merge(i * m + j, i * m - m + j);
            } else if (g[i][j] == 'D' && i < n - 1 && g[i + 1][j] == 'C') {
                dsu.merge(i * m + j, i * m + m + j);
            } else if (g[i][j] == 'R' && j < m - 1 && g[i][j + 1] == 'C') {
                dsu.merge(i * m + j, i * m + j + 1);
            } else if (g[i][j] == 'L' && j > 0 && g[i][j - 1] == 'C') {
                dsu.merge(i * m + j, i * m + j - 1);
            }
        }
    }
    int ok = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dsu.size(i * m + j) != 3) ok++;
        }
    }
    if (ok != 1) cout << "No\n";
    else cout << "Yes\n";
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