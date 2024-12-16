#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int> (n));

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v) swap(u, v);
        g[u][v] = 1;
    }

    cin >> m;
    vector<array<int, 2>> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i][0] >> e[i][1];
        e[i][0]--;
        e[i][1]--;
    }   

    vector<vector<int>> c(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> c[i][j];
            c[j][i] = c[i][j];
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    int ans = 1e9;

    do {
        vector<int> ref(n);
        for (int i = 0; i < n; i++) {
            ref[p[i]] = i;
        }

        int res = 0;
        vector<vector<int>> now(n, vector<int> (n));
        for (int i = 0; i < m; i++) {
            int u = e[i][0];
            int v = e[i][1];
            if (ref[u] > ref[v]) swap(u, v);
            now[ref[u]][ref[v]] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (g[i][j]) {
                    if (now[i][j]) continue;
                    else {
                        res += c[p[i]][p[j]];
                    }
                } else if (now[i][j]) {
                    res += c[p[i]][p[j]];
                }
            }
        }

        ans = min(ans, res);
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}