#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int  mod  = 1e9 + 7;

void solve() {
    int q;
    cin >> q;
    ll ans = 0;
    vector<ll> p;
    while (q--) {
        int t, v;
        cin >> t >> v;
        for (int i = 0; i < t; i++) {
            ll n = p.size();
            ans -= n % mod * p.back() % mod;
            if (ans < 0) ans += mod;
            p.pop_back(); 
        }
        p.push_back(v);
        ll n = p.size();
        ans += n % mod * v % mod;
        ans %= mod;
        if (ans < 0) ans += mod;
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}