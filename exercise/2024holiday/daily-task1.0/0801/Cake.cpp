#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> e(n);
    vector<double> ans(n, 1);

    for (int i = 1; i < n; i++) {
        int x, y, val;
        cin >> x >> y >> val;
        x--;
        y--;
        e[x].emplace_back(y, val);
        e[y].emplace_back(x, val);
    }

    auto dfs = [&](auto &&self, int x, int fa, int c1, int c2, int val, int d) -> void {
        if (val == 0) {
            c2++;
        } else {
            c1++;
        }
        ans[x] = min(ans[x], double(c1) / (c1 + c2)); 
        int ok = 0;
        double res = 0;

        for (auto [nxt, v] : e[x]) {
            if (nxt == fa) continue;
            ans[nxt] = ans[x];
            self(self, nxt, x, c1, c2, v, d + 1);
            if (d & 1) {
                if (!ok) {
                    res = ans[nxt];
                    ok = 1;
                }
                else res = min(ans[nxt], res);
            }
            else {
                if (!ok) {
                    res = ans[nxt];
                    ok = 1;
                }
                else res = max(res, ans[nxt]);
            }
        }
        if (ok) ans[x] = min(ans[x], res);
    };

    ans[0] = 0;
    for (auto [nxt, val] : e[0]) {
        dfs(dfs, nxt, 0, 0, 0, val, 1);
        ans[0] = max(ans[0], ans[nxt]);
    }

    cout << fixed << setprecision(12) << ans[0] << "\n";
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