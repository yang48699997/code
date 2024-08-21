#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 998244353;
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
    int n;
    cin >> n;
    int left = n % 3;
    n = (n - 1) / 3 + 1;
    n *= 3;
    if (left) n -= 2;
    ll ans = powMod(2, n);
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