#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int> (m));
    vector<vector<int>> b(n, vector<int> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    for (int k = 0; k < 30; k++) {
        vector<vector<int>> ta(n, vector<int> (m));
        vector<vector<int>> tb(n, vector<int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ta[i][j] = a[i][j] & 1;
                a[i][j] >>= 1;
                tb[i][j] = b[i][j] & 1;
                b[i][j] >>= 1;
            }
        }
        vector<int> cnt(m);
        vector<int> v(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[j]) ta[i][j] = 1;
            }
            if (ta[i] == tb[i]) {
                for (int j = 0; j < m; j++) {
                    cnt[j] += ta[i][j];
                }
                continue;
            }
            int ok = 1;
            for (int j = 0; j < m; j++) {
                if (ta[i][j] == tb[i][j]) continue;
                if (ta[i][j] == 1) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) {
                for (int j = 0; j < m; j++) {
                    ta[i][j] = 0;
                }
            }
            for (int j = 0; j < m; j++) {
                if (ta[i][j] == tb[i][j]) continue;
                if (cnt[j] != i) {
                    cout << "No\n";
                    return;
                }
                v[j] = 1;
                ta[i][j] = 1;
            }
            for (int j = 0; j < m; j++) {
                cnt[j] += (ta[i][j] | (!ok));
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