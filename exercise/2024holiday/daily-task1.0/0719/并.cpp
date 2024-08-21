#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
using ll = long long;
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
    cout << 11 * powMod(3, mod - 2) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}