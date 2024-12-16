#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    ll ans = 0;

    ll now = 1;
    while (l1 * now <= r2) {
        int L = max(l1 * now, l2);
        int R = min(r1 * now, r2);
        if (L > R) {
            now *= k;
            continue;
        }
        R = R / now;
        L = L / now + (L % now > 0);
        ans += R - L + 1;
        
        now *= k;
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