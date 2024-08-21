#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int ok = 0;
    vector<pair<int, int>> ans;

    vector<int> pre(n), v(n);
    for (int i = 0; i < n && !ok; i++) {
        if (e[i].size() < 4) continue;
        for (int p = 0; p < e[i].size() && !ok; p++) {
            for (int j = 0; j < n; j++) v[j] = 0;
            queue<int> q;
            q.push(e[i][p]);
            pre[e[i][p]] = i;
            v[e[i][p]] = 1;
            while (!q.empty() && !ok) {
                int x = q.front();
                q.pop();
                for (int nxt : e[x]) {
                    if (v[nxt]) continue;
                    if (nxt == i && x == e[i][p]) continue;
                    pre[nxt] = x;
                    v[nxt] = 1;
                    if (nxt == i) {
                        ok = 1;
                        break;
                    }
                    q.push(nxt);
                }
            }
            if (ok) {
                int now = i;
                do {
                    ans.emplace_back(now, pre[now]);
                    now = pre[now];
                } while (now != i);
                int c = 0;
                for (int j = 0; j < e[i].size() && c != 2; j++) {
                    if (j == p || e[i][j] == pre[i]) continue;
                    ans.emplace_back(i, e[i][j]);
                    c++;
                }
            }
        }
    }
    if (!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << "\n";
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