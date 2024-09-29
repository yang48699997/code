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
    int cnt = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'C') cnt++;
            else if (g[i][j] == '.') p++;
        }
    }
    if (cnt * 3 + 1 != n * m || p != 1 || g[0][m - 1] != '.') {
        cout << "No\n";
        return;
    }
    DSU dsu(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != 'C') continue;
            int now = 0;
            if (i > 0 && g[i - 1][j] == 'D') {
                dsu.merge(i * m + j, i * m + j - m);
                now++;
            }
            if (j > 0 && g[i][j - 1] == 'R') {
                dsu.merge(i * m + j, i * m + j - 1);
                now++;
            }
            if (j < m - 1 && g[i][j + 1] == 'L') {
                dsu.merge(i * m + j, i * m + j + 1);
                now++;
            }
            if (i < n - 1 && g[i + 1][j] == 'U') {
                dsu.merge(i * m + j, i * m + j + m);
                now++;
            }
            if (now != 2) {
                cout << "No\n";
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') continue;
            if (dsu.size(i * m + j) != 3) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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