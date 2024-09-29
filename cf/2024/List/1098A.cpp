#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        e[x].push_back(i);
    }
    vector<int> s(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    ll ans = 0;
    int ok = 1;
    auto dfs = [&](auto &&self, int x, ll pre) -> void {
        if (s[x] != -1 && s[x] < pre) {
            ok = 0;
            return;
        }
        if (d[x] & 1) {
            if (e[x].size() == 0) return;
            int mi = 1e9;
            for (int nxt : e[x]) {
                mi = min(s[nxt], mi);
                d[nxt] = d[x] + 1;
            }
            if (mi < pre) {
                ok = 0;
                return;
            }
            ans += mi - pre;
            for (int nxt : e[x]) {
                self(self, nxt, mi);
            }
        } else {
            ans += s[x] - pre;
            for (int nxt : e[x]) {
                d[nxt] = d[x] + 1;
                self(self, nxt, s[x]);
            }
        }
    };

    dfs(dfs, 0, 0);
    if (!ok) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}