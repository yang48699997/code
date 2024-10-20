#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);

    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    c--;

    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v); 
        e[v].push_back(u); 
    }

    vector<int> v(n), v1(n);
    v[a] = 1;
    auto dfs1 = [&](auto &&self, int x) -> int {
        if (x == c) {
            v1[x] = 1;
            return 1; 
        }
        for (int nxt : e[x]) {
            if (v[nxt]) continue;
            v[nxt] = 1;
            v1[x] |= self(self, nxt);
        }
        return v1[x];
    };

    dfs1(dfs1, a);
    if (v1[b]) {
        cout << "Yes\n";
        return;
    }

    vector<int> pre(n, -1);
    v.assign(n, 0);
    queue<int> q;
    q.push(b);
    v[b] = 1;
    int ok = 0;
    int tar = -1;
    while (!q.empty() && !ok) {
        int x = q.front();
        q.pop();
        for (int nxt : e[x]) {
            if (v[nxt]) continue;
            if (v1[nxt]) {
                tar = nxt;
                ok = 1;
                break;
            }
            v[nxt] = 1;
            pre[nxt] = x;
            q.push(nxt);
        }
    }

    ok = 0;
    q = queue<int>();
    v.assign(n, 0);
    while (tar != -1) {
        v[tar] = 1;
        tar = pre[tar];
    }
    q.push(b);
    while (!q.empty() && !ok) {
        int x = q.front();
        q.pop();
        for (int nxt : e[x]) {
            if (v[nxt]) continue;
            if (v1[nxt]) {
                ok = 1;
                break;
            }
            v[nxt] = 1;
            q.push(nxt);
        }
    }

    if (ok) cout << "Yes\n";
    else cout << "No\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}