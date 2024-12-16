#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll l, r, i, k;
    cin >> l >> r >> i >> k;
    i = 1LL << i;

    auto cal = [&](ll l) -> ll {
        ll res = 0;
        ll p = 1;
        for (int i = 0; i < 60; i++) {
            ll cnt = l / p / 2 * p;
            cnt += max(0LL, l % (p * 2) + 1 - p);
            if (cnt & 1) res |= p;
            p <<= 1;
        }

        return res;
    };

    ll ans = (cal(l - 1) ^ cal(r));

    auto cal2 = [&](ll l) -> ll {
        if (l < k) return 0;
        if (l % i < k) l -= i;
        ll res = cal(l / i) * i;
        ll cnt = l / i;
        if (cnt & 1 ^ 1) res |= k;

        return res;
    };

    ans ^= cal2(r);
    ans ^= cal2(l - 1);


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