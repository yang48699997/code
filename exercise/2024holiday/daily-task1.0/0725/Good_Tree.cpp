#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;
int T;
void solve() {
    ll x;
    cin >> x;
    ll ans = 1e18;
    ll l = 2, r = x + x % 2;
    auto cal1 = [&](ll p) -> ll {
        ll res = p + 1;
        res += x / p;
        if (x % p) res++;
        if ((x % p) && (x % p % 2 == 0)) res++;
        return res;
    };
    auto cal2 = [&](ll p) -> ll {
        if (x % 2) return inf;
        ll res = p + 1;
        res += x / p;
        if (x % p) res++;
        return res;
    };
    ll p = sqrt(x);
    for (ll i = max(1LL, p - 100); i <= p + 100; i++) {
        if (i % 2) ans = min(ans, cal1(i));
        else ans = min(ans, cal2(i));
    }
    cout << ans << "\n";
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