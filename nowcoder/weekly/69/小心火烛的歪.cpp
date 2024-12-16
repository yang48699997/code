#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<char>> g(n, vector<char> (m));
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '0') tot++;
        }
    }

    vector<vector<vector<char>>> p(q, vector<vector<char>> (n, vector<char> (m)));
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> p[i][j][k];
            }
        }
    }

    int ans = -1;
    vector<int> ok(1 << q);
    for (int i = 0; i < 1 << q; i++) {
        vector<vector<int>> mar(n, vector<int> (m));
        int cnt = 0;
        for (int k = 0; k < q; k++) {
            if (1 << k & i) {
                int can = 1;
                for (int l = 0; l < n; l++) {
                    for (int r = 0; r < m; r++) {
                        if (p[k][l][r] == '1' && g[l][r] == '1') {
                            can = 0;
                            break;
                        }
                    }
                }
                if (!can) continue;

                for (int l = 0; l < n; l++) {
                    for (int r = 0; r < m; r++) {
                        if (p[k][l][r] == '1' && mar[l][r] == 0) {
                            mar[l][r] = 1;
                            cnt++;
                        }
                    }
                }
            }
        }
        if (cnt != tot) continue;
        if (ans == -1) ans = i;
        else if (__builtin_popcount(ans) > __builtin_popcount(i)) ans = i;
    }

    if (ans == -1) {
        cout << ans << "\n";
        return;
    }

    int sum = __builtin_popcount(ans);
    cout << sum << "\n";
    int now = 0;
    for (int i = 0; i < q; i++) {
        if (1 << i & ans) {
            now++;
            cout << i + 1 << " \n"[now == sum];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}