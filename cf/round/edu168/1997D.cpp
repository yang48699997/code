#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> e(n);
    for (int i = 1; i < n; i++) {
        int fa;
        cin >> fa;
        fa--;
        e[i].push_back(fa);
        e[fa].push_back(i);
    }


    auto dfs = [&](auto &&self, int x, int fa) -> int {
        int mi = -1;
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            int res = self(self, nxt, x);
            if (mi == -1) mi = res;
            else mi = min(mi, res);
        }
        if (mi == -1) return a[x];
        if (a[x] < mi) return (a[x] + mi) / 2;
        else return mi;
    };

    int ans = 1e9;
    for (int nxt : e[0]) {
        ans = min(ans, dfs(dfs, nxt, 0));
    }
    ans += a[0];
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