#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> e(n), e2(n);
    vector<array<int, 2>> p;
    vector<int> deg(n), deg2(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;

        p.push_back({u, v});
    }

    if (n == 2) {
        cout << "Yes\n";
        cout << "1 2\n";
        return;
    }

    vector<int> l;
    for (int i = 0; i < n - 1; i++) {
        int u = p[i][0];
        int v = p[i][1];
        if (deg[u] == 1 || deg[v] == 1) {
            continue;
        }
        
        deg2[u]++;
        deg2[v]++;
        
        e2[u].push_back(v);
        e2[v].push_back(u);
    }

    int now = -1;
    for (int i = 0; i < n; i++) {
        if (deg2[i] == 1) {
            if (now != -1) continue;
            now = i;
            l.push_back(i);
        } else if (deg2[i] > 2) {
            cout << "No\n";
            return;
        } else if (deg2[i] == 0 && deg[i] > 1) {
            now = i;
            l.push_back(i);
        }
    }

    auto dfs = [&](auto &&self, int x, int fa) -> void {        
        for (int nxt : e2[x]) {
            if (nxt == fa) continue;
            l.push_back(nxt);
            self(self, nxt, x);
        }
    };

    dfs(dfs, now, -1);

    vector<int> v;
    for (int i = 0; i < l.size(); i += 2) {
        v.push_back(l[i]);
    }
    for (int i = l.size() - l.size() % 2 - 1; i >= 0; i -= 2) {
        v.push_back(l[i]);
    }
    
    cout << "Yes\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] + 1 << ' ';
        for (int nxt : e[v[v.size() - 1 - i]]) {
            if (deg[nxt] == 1) cout << nxt + 1 << " ";
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}