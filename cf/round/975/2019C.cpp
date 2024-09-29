#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    ll mx = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(a[i], mx);
    }
    int ans = 0;
    ll l = sum, r = sum + k;

    for (int i = n; i > 0; i--) {
        ll p = (sum - 1) / i + 1;
        p = max(p, mx);
        p *= i;
        if (p <= r) {
            ans = i;
            break;
        }
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