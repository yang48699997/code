#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    ll ans = 1;
    if (n == inf) ans++;
    for (int i = 3; i <= min(999LL, n); i++) {
        ll cur = n;
        while (cur) {
            if (cur % i != 0 && cur % i != 1) break;
            cur /= i;
        }
        ans += (cur == 0);
    }
    auto check = [&](int x) -> int {
        ll l = 1000, r = inf;
        while (l <= r) {
            ll mid = (r - l) / 2 + l;
            ll res = 0;
            ll p = 1;
            for (int j = 0; j < 6; j++) {
                if (x >> j & 1) {
                    res += p;
                    if (res > inf) break;
                }
                if (p  > inf / mid) p = inf + 1;
                else p = p * mid;
            }
            if (res > n) r = mid - 1;
            else l = mid + 1;
        }
        if (r == 999) return 0;
        ll res = 0;
        ll p = 1;
        for (int j = 0; j < 6; j++) {
            if (x >> j & 1) {
                res += p;
                if (res > inf) break;
            }
            if (p  > inf / r) p = inf;
            else p = p * r;
        }
        return res == n;
    };
    for (int i = 1; i < 1 << 6; i++) {
        ans += check(i);
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