#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> e(n);
    vector<int> f(n, -1);
    for (int i = 1; i < n; i++) {
        int fa;
        cin >> fa;
        fa--;
        f[i] = fa;
        e[fa].push_back(i);
    }

    vector<int> d(n);
    vector<int> cnt(n);
    auto dfs = [&](auto &&self, int x, int fa) -> int {
        d[x] = d[fa] + 1;
        int mx = d[x];
        for (int nxt : e[x]) {
            mx = max(mx, self(self, nxt, x));
        }
        cnt[mx - d[x]]++;
        return mx;
    };


    dfs(dfs, 0, 0);

    int ans = n;
    for (int i = 0; i < n; i++) {
        ans = min(ans, cnt[i] + i);
    }

    cout << ans << "\n";
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