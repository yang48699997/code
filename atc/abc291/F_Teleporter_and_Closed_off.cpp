#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<vector<int>> e1(n);
    vector<vector<int>> e2(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                e1[i].push_back(i + j + 1);
                e2[i + j + 1].push_back(i);
            }
        }
    }

    const int inf = 1e9;
    vector<int> dp1(n, inf);
    vector<int> dp2(n, inf);
    dp1[0] = dp2[n - 1] = 0;
    for (int i = 0; i < n; i++) {
        if (dp1[i] == inf) continue;
        for (int nxt : e1[i]) {
            dp1[nxt] = min(dp1[nxt], dp1[i] + 1);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (dp2[i] == inf) continue;
        for (int nxt : e2[i]) {
            dp2[nxt] = min(dp2[nxt], dp2[i] + 1);
        }
    }

    for (int i = 1; i < n - 1; i++) {
        int ans = inf;
        for (int j = i + 1; j < min(n, i + m); j++) {
            int res = dp2[j];
            if (res == inf) continue;
            for (int nxt : e2[j]) {
                if (nxt >= i) continue;
                ans = min(ans, res + 1 + dp1[nxt]);
            }
        }
        cout << (ans == inf ? -1 : ans) << " \n"[i == n - 2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}