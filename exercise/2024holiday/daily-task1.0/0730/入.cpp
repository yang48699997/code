#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

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
    vector<ll> p(n);
    ll r = 1;
    for (int i = 0; i < n; i++) {
        p[i] |= (r << i);
        for (int nxt : e[i]) {
            p[i] |= (r << nxt);
        }
    }
    
    auto dfs = [&](auto && self, int x, ll d) -> int {
        int mx = 0;
        vector<int> a;
        for (int nxt : e[x]) {
            if (d & (r << nxt)) continue;
            mx = max(mx, self(self,nxt, d | p[x]));
        }
        return mx + 1;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dfs(dfs, i, r << i));
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}