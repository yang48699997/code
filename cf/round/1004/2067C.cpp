#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x;
    cin >> x;

    string s = to_string(x);

    int ans = (3 + x % 10) % 10;
    ans = min(ans, 7);

    ll p = 10;
    for (int i = s.size() - 2; i >= 0; i--) {
        p *= 10;
        int res = 0;
        ll tmp = x;

        while (tmp * 10 / p % 10 != 7) {
            if (tmp % p >= p / 10 * 8) {
                ans = min(ans, (int)(tmp % p - p / 10 * 8 + 1));
            }
            res++;
            tmp += p / 10 - 1;
        }

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