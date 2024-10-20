#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;


void solve() {
    i128 n, m;
    ll k, a, b;
    ll n_, m_;
    cin >> n_ >> k >> m_;
    n = n_;
    m = m_;
    cin >> a >> b;

    ll ans = 1e18;

    auto cal = [&](i128 now, ll tar) -> ll {
        ll cnt = 0;
        i128 l = now, r = now;
        while (l / m == r / m && l % m != 0 && r % m != 0) {
            cnt++;
            l = l * k;
            r = r * k + k - 1;
        }
        return cnt;
    };

    if (k == 1) {
        cout << ((n % m == 0) ? 0 : -1) << "\n";
        return;
    } else {
        ll now = 0;
        while (n > 0) {
            ans = min(ans, cal(n, m) * a + now);
            now += b;
            n /= k;
        }
        ans = min(ans, now);
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