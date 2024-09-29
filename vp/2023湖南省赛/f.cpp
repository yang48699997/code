#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    const int mx = 400;
    vector<vector<int>> c(401, vector<int> (401, inf));
    for (int i = 0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        c[x][y] = min(c[x][y], t);
    }
    for (int i = 0; i <= 400; i++) c[i][i] = 0;
    for (int i = 1; i <= mx; i++) {
        for (int j = 1; j <= mx; j++) {
            for (int k = 1; k <= mx; k++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    int ans = inf;
    for (int k = 0; k < n; k++) {
        int res = 0;
        int ok = 1;
        for (int i = 0; i < n; i++) {
            int p = min(c[a[i]][b[(i + k) % n]], c[b[(i + k) % n]][a[i]]);
            if (p == inf) {
                ok = 0;
                break;
            } else res += p;
        }
        if (ok) ans = min(ans, res);
    }

    cout << (ans == inf ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}