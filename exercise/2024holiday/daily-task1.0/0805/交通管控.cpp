#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k, mod;
    cin >> n >> k >> mod;

    vector<int> dp(1 << k << k, 0);
    vector<int> ok(1 << k << k, 0);
    vector<int> tok(1 << k << k, 0);
    vector<int> tmp(1 << k << k, 0);
    dp[0] = 1;
    ok[0] = 1;
    vector<int> p;
    auto dfs = [&](auto &&self, int i, int pre) -> void {
        if (i == k) {
            p.push_back(pre);
            return;
        }
        pre <<= 2;
        for (int j = 0; j < 3; j++) {
            self(self, i + 1, pre + j);
        }
    };
    dfs(dfs, 0, 0);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < p.size(); j++) {
            tmp[p[j]] = tok[p[j]] = 0;
        }

        for (int j = 0; j < p.size(); j++) {
            int now = p[j];
            int nxt = 0;
            for (int l = 0; l < k * 2; l += 2) {
                int cur = (now >> l & 3);
                if (s[l / 2] == '+') cur = (cur + 1) % 3;
                else if (s[l / 2] == '-') cur = (cur - 1 + 3) % 3;
                nxt |= (cur << l);
            }
            tmp[nxt] = (tmp[nxt] + dp[now]) % mod;
            tok[nxt] |= ok[now];
        }
        for (int j = 0; j < p.size(); j++) {
            dp[p[j]] = (dp[p[j]] + tmp[p[j]]) % mod;
            ok[p[j]] |= tok[p[j]];
        }
    }

    vector<string> ans;
    vector<int> b;
    for (int i = 0; i < p.size(); i++) {
        int now = p[i];
        if (!ok[now]) continue;
        string s;
        for (int l = 0; l < k * 2; l += 2) {
            int cur = (now >> l & 3);
            s += 'A' + cur;
        }
        ans.push_back(s);
        b.push_back(dp[now]);
    }

    vector<int> q((int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        q[i] = i;
    }
    sort(q.begin(), q.end(), [&](int x1, int x2) {
        return ans[x1] < ans[x2];
    });

    for (int i : q) {
        cout << ans[i] << " " << b[i] << "\n";
    }
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