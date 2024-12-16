#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
    }

    queue<int> q;
    vector<int> d(n);

    q.push(0);
    d[0] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nxt : e[x]) {
            if (nxt == 0) {
                cout << d[x] << "\n";
                return;
            }
            if (d[nxt]) continue;
            d[nxt] = d[x] + 1;
            q.push(nxt);
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}