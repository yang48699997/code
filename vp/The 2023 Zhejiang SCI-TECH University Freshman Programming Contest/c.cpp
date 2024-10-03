#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<int, int> mp;
    for (int i = 2; i < 1e6 && k != 1; i++) {
        if (k % i != 0) continue;
        while (k % i == 0) {
            mp[i]++;
            k /= i;
        }
    }
    int m = mp.size();
    vector<ll> dp(1 << m);
    for (int i = 0; i < n; i++) {
        int ok = 1;
        int p = (1 << m) - 1;
        int c = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int cnt = 0;
            int x = it -> first;
            int t = it -> second;
            while (a[i] % x == 0) {
                cnt++;
                a[i] /= x;
            }
            if (cnt > t) {
                ok = 0;
                break;
            } else if (cnt == t) {
                p ^= 1 << c;
            }
            c++;
        }
        if (a[i] > 1) ok = 0;
        if (ok) dp[p]++;
    }


    for (int i = (1 << m) - 1; i > 0; i--) {
        for (int now = ((i - 1) & i); now; now = ((now - 1) & i)) {
            dp[i] += dp[now];
        }
        dp[i] += dp[0];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int ok = 1;
        int p = 0;
        int c = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int cnt = 0;
            int x = it -> first;
            int t = it -> second;
            while (b[i] % x == 0) {
                cnt++;
                b[i] /= x;
            }
            if (cnt > t) {
                ok = 0;
                break;
            } else if (cnt == t) {
                p |= 1 << c;
            }
            c++;
        }
        if (b[i] > 1) ok = 0;
        if (ok) ans += dp[p];
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