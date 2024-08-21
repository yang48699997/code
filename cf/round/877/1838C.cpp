#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int> (m));
    
    int tot = 0;
    if (m & 1 && n & 1) {   
        for (int i = 0; i < n / 2 + 1; i++) {
            for (int j = 0; j < m; j++) {
                g[i][j] = i * m * 2 + j + 1;
            }
        }
        for (int i = n / 2 + 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[i][j] = (i - n / 2 - 1) * 2 * m + j + 1 + m;
            }
        }
    } else if (m % 2 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[i][j] = ++tot;
            }
        }
    } else {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                g[i][j] = ++tot;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j] << " \n"[j == m - 1];
        }
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