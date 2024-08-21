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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;    
    vector<ll> power(n + 1);
    for (int i = 1; i <= n; i++) {
        power[i] = powMod(i, k);
    }

    ll ans = 0;
    ll p1 = 0, p2 = 0, pl = 0;
    ll last = 0;
    ll res = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            p1 = p2 = res = 0;
            last = pl = 0;
        } else {
            ll p = 1;
            if (s[i] == '?') p = powMod(2, mod - 2);
            if (p1 == 0) {
                res = p;
                p1 = p;
                p2 = 0;
                pl = p;
                last = 1;
            } else {
                res -= p1;
                if (res < 0) res += mod;
                res *= powMod(p2, mod - 2);
                res %= mod;
                res = res * p1 % mod;
                res = (res + pl * power[++last] + 1) % mod;
                res = p * res % mod;
                p2 = p1 * p % mod;
                p1 = p;
                pl = pl * p % mod;
            }
        }
        ans = (ans + res) % mod;
        // cerr << res << "\n";
    }
    // cerr << 39 * powMod(8, mod - 2) % mod;
    // cerr << 47 * powMod(8, mod - 2) % mod;
    cout << ans << "\n";
    res = 0;
    for (int i = 0; i < n; i++) {
        ll p = 1;
        for (int j = i; j >= 0; j--) {
            if (s[j] == '0') p = 0;
            else if (s[j] == '?') p = p * powMod(2, mod - 2) % mod;
            res += power[i - j + 1] * p;
            res %= mod; 
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}