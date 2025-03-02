#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 1e9;

void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    s1--;
    s2--;

    int m1;
    cin >> m1;
    vector<vector<int>> e1(n);
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e1[u].push_back(v);
        e1[v].push_back(u);
    }

    int m2;
    cin >> m2;
    vector<vector<int>> e2(n);
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e2[u].push_back(v);
        e2[v].push_back(u);
    }

    vector<vector<int>> dp(n, vector<int> (n, inf));
    vector<vector<int>> v(n, vector<int> (n));
    dp[s1][s2] = 0;

    priority_queue<array<int, 3>> q;
    q.push({0, s1, s2});

    while (!q.empty()) {
        auto [d, x, y] = q.top();
        q.pop();
        d = -d;

        if (v[x][y]) continue;
        v[x][y] = 1;

        for (int nxt1 : e1[x]) {
            for (int nxt2 : e2[y]) {
                if (x == y && nxt1 == nxt2) {
                    cout << d << "\n";
                    return;
                }
                int d2 = d + abs(nxt1 - nxt2);
                if (!v[nxt1][nxt2] && d2 < dp[nxt1][nxt2]) {
                    dp[nxt1][nxt2] = d2;
                    q.push({-d2, nxt1, nxt2});
                }
            }
        }
    }
    cout << "-1\n";
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