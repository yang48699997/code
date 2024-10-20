#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int> (m));
    vector<vector<int>> v(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    v[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!v[i][j]) continue;
            if (j < m - 1 && g[i][j + 1] == g[0][0]) v[i][j + 1] = 1; 
            if (i < n - 1 && g[i + 1][j] == g[0][0]) v[i + 1][j] = 1; 
        }
    }

    if (v[n - 1][m - 1]) cout << "Yes\n";
    else cout << "No\n";
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