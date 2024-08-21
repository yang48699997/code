#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int T;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }    
    vector<vector<ll>> dp(n,vector<ll> (20));
    auto dfs = [&](auto &&self, int x, int fa) -> void {
        for (int i = 0; i < 20; i++) {
            dp[x][i] = a[x] * (i + 1);
        }
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            self(self, nxt, x);
            for (int i = 0; i < 20; i++) {
                ll p = 3e18;
                for (int j = 0; j < 20; j++) {
                    if (j == i) continue;
                    p = min(p, dp[nxt][j]);
                }
                dp[x][i] += p;
            }
        }
    };
    dfs(dfs, 0, -1);
    ll ans = 3e18;
    for (int i = 0; i < 20; i++) ans =  min(ans, dp[0][i]);
    cout << ans << "\n";
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