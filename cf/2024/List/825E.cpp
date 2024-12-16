#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    vector<int> deg(n), ans(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[v].push_back(u);
        deg[u]++;
    }

    priority_queue<int> q;
    int now = n;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.top();
        q.pop();
        ans[x] = now--;
        for (int nxt : e[x]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}