#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> ex(n);
    for (int i = 0; i < n; i++) cin >> ex[i];

    vector<int> ans(m);
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<int> c(m);
    int res = -1e9;
    vector<int> nums(m);
    iota(nums.begin(), nums.end(), 0);

    auto dfs = [&](auto &&self, int x, int k) -> void {
        if (k == n) {
            sort(nums.begin(), nums.end(), [&](int x, int y) {
                return c[x] > c[y];
            });            
            for (int i = 0; i < m; i++) {
                x += (m - i) * c[nums[i]];
            }
            if (x <= res) return;
            res = x;
            for (int i = 0; i < m; i++) {
                ans[nums[i]] = m - i;
            }
            return;
        }

        for (int i = 0; i < m; i++) {
            if (s[k][i] == '1') {
                c[i]++;
            }
        }
        self(self, x - ex[k], k + 1);
        for (int i = 0; i < m; i++) {
            if (s[k][i] == '1') {
                c[i] -= 2;
            }
        }
        self(self, x + ex[k], k + 1);
        for (int i = 0; i < m; i++) {
            if (s[k][i] == '1') {
                c[i]++;
            }
        }
    };

    dfs(dfs, 0, 0);
    
    for (int i = 0; i < m; i++) cout << ans[i] << " \n"[i == m - 1];
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