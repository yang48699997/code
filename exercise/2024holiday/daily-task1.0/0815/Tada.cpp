#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int to_int(string &s) {
    int res = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int N = 1;
    for (int i = 0; i < n; i++) N *= 10;
    vector<int> v(N, 1);

    auto dfs = [&](auto &&self, int x, int y, int i, int lef, int op, int ok) -> int {
        if (i == n) {
            if (lef < 0) return 0;
            if (n == 1 && (lef % 2)) return 0;
            if (lef == 1 && !ok) return 0;
            return 1;
        }
        int l1 = x % 10;
        int l2 = y % 10;
        x /= 10;
        y /= 10;
        int p = (l1 + 10 - l2) % 10;
        int p2 = p - 10;
        if (p == 0) p2 = 0;
        int res = 0;
        res |= self(self, x, y, i + 1, lef - max(0, p - max(0, op)), p, ok | (p > 0));
        res |= self(self, x, y, i + 1, lef - max(0, min(0, op) - p2), p2, ok | (p2 < 0));
        return res;
    };

    while (m--) {
        string s;
        int t;
        cin >> s >> t;
        int now = to_int(s);
        for (int i = 0; i < N; i++) {
            v[i] &= dfs(dfs, now, i, 0, t, 0, 0);
        }
    }
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (v[i]) {
            cnt++;
            ans = i;
        }
    }
    string res;
    for (int i = 0; i < n; i++) {
        res += '0' + ans % 10;
        ans /= 10;
    }
    if (cnt > 1) cout << "MANY\n";
    else if (cnt == 0) cout << "IMPOSSIBLE\n";
    else cout << res << "\n";
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