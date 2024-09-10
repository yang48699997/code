#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll cal(ll x) {
    if (x <= 0) return 0LL;
    return x * (x + 1) / 2;
}
void solve() {
    ll n, k;
    cin >> k >> n;
    ll t = cal(n + k - 1) + cal(n - 1);
    ll p = sqrt(t);
    ll ans = 1e18;
    for (int i = -1; i < 2; i++) {
        ll now = p + i;
        if (now < n || now >= n + k) continue;
        ans = min(ans, abs(-cal(now) + cal(n + k - 1) - cal(now) + cal(n - 1)));
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