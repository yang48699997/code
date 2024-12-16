#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 10;

ll dp[1 << N][N + 1];

void init() {
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    for (int j = 1; j <= N; j++) {
        for (int i = 0; i < 1 << N; i++) {
            for (int k = 0; k < 10; k++) {
                dp[i | (1 << k)][j] += dp[i][j - 1];
            }
        }
    }
    
}


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int, ll> solve(ll l, ll r) {

    string L = to_string(l);
    string R = to_string(r);

    auto dfs = [&](auto &&self, string &s, int limited, int mex, int mask, int pos) -> ll {
        int p = (1 << mex) - 1;
        int n = s.size();

        if (pos == n) {
            return (mask & p) == p;
        }

        if (!limited) {
            ll res = 0;
            for (int i = 0; i < 1 << N; i++) {
                if (((mask | i) & p) == p) res += dp[i][n - pos];
            }
            return res;
        }

        ll res = 0;
        for (int j = 0; j <= s[pos] - '0'; j++) {
            if (pos == 0 && j == 0 && n != 1) continue;
            res += self(self, s, limited && (j == s[pos] - '0'), mex, (mask | 1 << j), pos + 1);
        }


        return res;
    };

    for (int i = 10; i > 0; i--) {
        ll res = dfs(dfs, R, 1, i, 0, 0) - dfs(dfs, L, 1, i, 0, 0);
        if (res) {
            return make_pair(i, res);
            cout << i << " " << res << "\n";
        }
    }

    return make_pair(0, r);
    // cout << 0 << " " << k + 1 << "\n";
}

pair<int, ll> solve2(ll l, ll r) {

    vector<ll> cnt(11);
    for (int i = 1; i <= r; i++) {
        vector<int> v;
        int now = i;
        while (now) {
            v.push_back(now % 10);
            now /= 10;
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int res = v.size();
        for (int j = 0; j < v.size(); j++) {
            if (v[j] != j) {
                res = j;
                break;
            }
        }
        cnt[res]++;
    }

    for (int i = 10; i >= 0; i--) {
        if (cnt[i] == 0) continue;
        else return make_pair(i, cnt[i]);
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();

    int T;
    // cin >> T;
    while (1) {
        ll r = rng() % 1000000000;
        if (solve(0, r) != solve2(0, r)) {
            cout << r << ": \n" << solve(0, r).first << " " << solve(0, r).second << "\n";
            cout << solve2(0, r).first << " " << solve2(0, r).second << "\n";
            break;
        }
    }
    return 0;
}