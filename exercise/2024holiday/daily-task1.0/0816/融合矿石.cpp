#include <bits/stdc++.h>
using namespace std;

using ll = long long;



void solve() {
    vector<ll> v(10);
    for (int i = 0; i < 10; i++) cin >> v[i];

    int n, m;
    cin >> n >> m;
    vector<ll> dp(m + 1);
    vector<int> vv(m + 1);
    vv[0] = 1;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        for (int j = x; j <= m; j++) {
            if (dp[j - x] + y >= dp[j] && vv[j - x]) {
                dp[j] = dp[j - x] + y;
                vv[j] = 1;
            } 
        }
    }

    ll ans = 0;
    vector<ll> p(m + 1);
    for (ll i = 1; i <= m; i++) {
        if (!vv[i]) continue;
        int l = dp[i] * 10 / i - 1;
        if (dp[i] * 10 % i) l++;    
        p[i] = v[l] * i;
    }

    vector<ll> pp(m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            pp[j] = max(pp[j], pp[j - i] + p[i]);
            ans = max(ans, pp[j]);
        }
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