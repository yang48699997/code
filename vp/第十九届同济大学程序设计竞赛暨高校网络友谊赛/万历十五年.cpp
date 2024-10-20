#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mx = 5e5 + 5;
const int inf = 1e9;
bitset<mx> bt;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> sz(n, 1);
    vector<int> ans(n);
    auto dfs = [&](auto &&self, int x, int fa) -> void {
        vector<int> p;
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            self(self, nxt, x);
            sz[x] += sz[nxt];
            p.push_back(sz[nxt]);
        }
        if (p.empty()) return;
        sort(p.rbegin(), p.rend());
        if (p[0] * 2 >= sz[x] - 1) {
            ans[x] = p[0] * 2 - sz[x] + 1;
        } else {
            reverse(p.begin(), p.end());
            bt.reset();
            bt.set(0);
            for (int i = 0; i < p.size();) {
                int j = i;
                int cnt = 0;
                while (j < p.size() && p[i] == p[j]) {
                    cnt++;
                    j++;
                }
                i = j;
                j = p[j - 1];
                for (int k = 1; k <= cnt; k <<= 1) {
                    bt |= bt << (k * j);
                    cnt -= k;
                }
                if (cnt) bt |= bt << (j * cnt);
            }
            ans[x] = inf;
            for (int i = 0; i < mx; i++) {
                if (bt.test(i)) {
                    ans[x] = min(ans[x], abs(i * 2 - sz[x] + 1));
                }
            }
        }
    };

    dfs(dfs, 0, -1);

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