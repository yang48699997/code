#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9; 

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int ans = inf;

    int p = 0;
    for (int i = 0; i < m; i++) p = p * 2 + s[0][i] - '0';

    auto dfs = [&](auto &&self, int l, int now, int op,int ok, int cnt) -> int {
        if (l == n) {
            if (now == ok) return cnt;
            else return inf;
        }
        int cur = 0;
        for (int i = 0; i < m; i++) cur = cur * 2 + s[l][i] - '0';
        now ^= ok;
        cnt += __builtin_popcount(now);
        cur ^= op;
        op = 0;
        for (int i = 0; i < m; i++) {
            if (now >> i & 1) {
                cur ^= 1 << i;
                op |= 1 << i;
                if (i < m - 1)cur ^= 1 << i << 1;
                if (i > 0)cur ^= 1 << i >> 1;
            }
        }
        return self(self, l + 1, cur, op, ok, cnt);
    };

    for (int i = 0; i < 1 << m; i++) {
        int op = 0;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) op ^= 1 << j;
            else continue;
            if (j > 0) op ^= 1 << (j - 1);
            if (j < m - 1) op ^= 1 << (j + 1);
        }
        int res = p ^ op;
        ans = min(ans, dfs(dfs, 1, res, i, 0, __builtin_popcount(i)));
        ans = min(ans, dfs(dfs, 1, res, i, (1 << m) - 1, __builtin_popcount(i)));
    }

    if (ans == inf) cout << "Impossible\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}