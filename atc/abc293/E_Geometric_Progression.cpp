#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod;

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
    ll a, x;
    cin >> a >> x >> mod;
    map<ll,ll> mp;
    auto dfs = [&](auto &&self, ll i) -> ll {
        if (i == 1) return 1 % mod;
        if (mp.count(i)) return mp[i];
        ll ans = 0;
        ans += self(self, i / 2);
        ll p = powMod(a, i / 2);
        ans += ans * p;
        if (i % 2) ans += powMod(a, i - 1);
        ans %= mod;
        mp[i] = ans;
        return ans;
    };
    ll ans = dfs(dfs, x);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}