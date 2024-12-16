#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll inf = 1e18;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n, vector<ll> (n, inf));
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i][0] >> e[i][1] >> e[i][2];
        e[i][0]--;
        e[i][1]--;
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    vector<array<int, 3>> ask(q);
    vector<int> vis(m, true);
    for (int i = 0; i < q; i++) {
        cin >> ask[i][0];
        if (ask[i][0] == 2) {
            cin >> ask[i][1] >> ask[i][2];
            ask[i][1]--;
            ask[i][2]--;
        } else {
            cin >> ask[i][1];
            ask[i][1]--;
            vis[ask[i][1]] = false;
        }
    }

    for (int i = 0; i < m; i++) {
        if (!vis[i]) continue;
        dist[e[i][0]][e[i][1]] = dist[e[i][1]][e[i][0]] = min(dist[e[i][0]][e[i][1]], 1LL * e[i][2]);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<ll> ans;
    while (q--) {
        if (ask[q][0] == 2) {
            ll res = dist[ask[q][1]][ask[q][2]];
            if (res == inf) res = -1;
            ans.push_back(res);
        } else {
            int u = e[ask[q][1]][0], v = e[ask[q][1]][1];
            ll c = e[ask[q][1]][2];
            if (c >= dist[u][v]) continue;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min({dist[i][j], dist[i][v] + c + dist[u][j], dist[i][u] + c + dist[v][j]});
                }
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}