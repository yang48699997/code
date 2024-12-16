#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = c * b;

    ll now = 1;
    ll p = 0;
    while (now <= c) {
        now *= 2;
        p += a;
        ll res = p + (c - 1) / now * b + b; 
        ans = min(ans, res);
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