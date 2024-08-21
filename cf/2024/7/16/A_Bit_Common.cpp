#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod;

ll powMod(ll x, ll y) {
    ll res = 1;
    while (y) {
        if(y & 1)res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    };
    return res;
};
void solve() {
    int n, m;
    cin >> n >> m >> mod;
    vector<vector<ll>> c(n + 1, vector<ll> (n + 1));
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    ll ans = 0;
    vector<ll> a(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] * 2 % mod;
    }
    for (int i = 1; i <= n; i++) {
        ll sum = (a[i] - 1) * a[n - i] % mod;
        sum = powMod(sum, m - 1);
        ans += sum * c[n][i] % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}