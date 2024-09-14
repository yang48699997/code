#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int l = (n + 1) / 2;
    int r = n - l;
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [&](int x1, int x2) {
        return b[x1] > b[x2];
    }); 
    vector<array<ll, 4>> dp(1 << l);
    for (int i = 0; i < 1 << l; i++) {
        ll sum = 0;
        vector<ll> tmp;
        dp[i][0] = i;
        for (int j = 0; j < l; j++) {
            if (1 << j & i) {
                sum += a[nums[j]];
                tmp.push_back(b[nums[j]]);
                dp[i][3] += b[nums[j]];
            }
        }
        dp[i][2] = sum;
        if (sum > m) {
            continue;
        }
        sort(tmp.begin(), tmp.end());
        for (int j = 0; j < tmp.size(); j++) {
            dp[i][1] += j * tmp[j];
        }
    }

    vector<vector<pair<ll, ll>>> p(r + 1);
    for (int i = 0; i < 1 << r; i++) {
        ll sum = 0;
        vector<ll> tmp;
        for (int j = 0; j < r; j++) {
            if (1 << j & i) {
                sum += a[nums[j + l]];
                tmp.push_back(b[nums[j + l]]);
            }
        }
        if (sum > m) {
            continue;
        }
        ll res = 0;
        sort(tmp.begin(), tmp.end());
        for (int j = 0; j < tmp.size(); j++) {
            res += j * tmp[j];
        }
        p[__builtin_popcount(i)].emplace_back(sum, res);
    }

    vector<vector<ll>> pre(r + 1);
    for (int i = 1; i <= r; i++) {
        sort(p[i].begin(), p[i].end());
        pre[i].resize(p[i].size() + 1, 0);
        for (int j = 0; j < p[i].size(); j++) {
            pre[i][j + 1] = max(pre[i][j], p[i][j].second);
        }
    }
    ll ans = 0;
    const ll inf = 1e18;
    for (int i = 0; i < 1 << l; i++) {
        if (dp[i][2] > m) continue;
        ans = max(ans, dp[i][1]);
        for (int j = 1; j <= r; j++) {
            // if (p[j].empty())
            auto it = lower_bound(p[j].begin(), p[j].end(), make_pair(m - dp[i][2], inf));
            if (it == p[j].begin()) continue;
            int pp = it - p[j].begin();
            ans = max(ans, dp[i][3] * j + dp[i][1] + pre[j][pp]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}