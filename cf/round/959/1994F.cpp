#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    vector<vector<int>> g(n);
    vector<int> edge(m);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        edge[i] = (x ^ y);
        e[x].push_back(i);
        e[y].push_back(i);
        if (c == 0) {
            g[x].push_back(i);
            g[y].push_back(i);
        }
        deg[x] ^= 1;
        deg[y] ^= 1;
    }

    vector<int> v(n);
    vector<int> del(m);
    auto dfs = [&](auto self, int x) -> void {
        v[x] = 1;
        for (int i : g[x]) {
            int nxt = (edge[i] ^ x);
            if (v[nxt]) continue;
            self(self, nxt);
            if (deg[nxt]) {
                del[i] = 1;
                deg[nxt] ^= 1;
                deg[x] ^= 1;
            }
        }
    };

    int ok = 1;
    for (int i = 0; i < n; i++) {
        if (!v[i]) dfs(dfs, i);
        else continue;
        ok &= !deg[i];
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    vector<int> ans;
    vector<int> p(n);
    auto work = [&](auto self, int x) -> void {
        for (int &i = p[x]; i < e[x].size(); i++) {
            if (del[e[x][i]]) continue;
            del[e[x][i]] = 1;
            self(self, x ^ edge[e[x][i]]);
        }
        ans.push_back(x);
    };

    work(work, 0);

    cout << ans.size() - 1 << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}