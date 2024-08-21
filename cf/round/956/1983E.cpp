#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll powMod(ll x, ll y) {
    ll res = 1;
    while (y) {
        if(y & 1)res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    };
    return res;
};

int T;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    ll tot1 = 0, tot2 = 0;
    for (int i = 0; i < k; i++) tot1 += a[i];
    for (int i = k; i < n; i++) tot2 += a[i];
    tot1 %= mod;
    tot2 %= mod;
    ans += (n - k + 1) / 2 * powMod(n - k, mod - 2) % mod * tot2 % mod;
    ans += (n - k + 2) / 2 * powMod(n - k + 1, mod - 2) % mod * tot1 % mod;
    ans %= mod;
    ll res = (tot1 + tot2 - ans + mod) % mod;
    cout << ans << " " << res << "\n";
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