#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ans(n), val(n);
    vector<int> deg(n), deg2(n);
    vector<vector<int>> e(n), e2(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e2[v].push_back(u);
        deg[v]++;
        deg2[u]++;
    }

    iota(val.begin(), val.end(), 0);
    queue<int> q2;
    for (int i = 0; i < n; i++) {
        if (deg2[i] == 0) {
            q2.push(i);
        }
    }

    while (!q2.empty()) {
        int x = q2.front();
        q2.pop();
        for (int nxt : e2[x]) {
            deg2[nxt]--;
            val[nxt] = min(val[nxt], val[x]);
            if (deg2[nxt] == 0) q2.push(nxt);
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < n; i++) {
        if (deg[i]) continue;
        q.push({val[i], i});
    }

    int cnt = 1;
    while (!q.empty()) {
        auto [_, x] = q.top();
        ans[x] = cnt++;
        q.pop();
        for (int nxt : e[x]) {
            if (--deg[nxt] == 0) q.push({val[nxt], nxt}); 
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