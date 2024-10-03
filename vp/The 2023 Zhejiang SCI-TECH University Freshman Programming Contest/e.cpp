#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    ll m, x;
    cin >> n >> m >> k >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = min(n / k * k * 1LL, m / x * k);
    sort(a.begin(), a.end());
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum > m) break;
        int res = i + 1;
        ll lef = m - sum;
        res += min((n - res) / k * k * 1LL, lef / x * k);
        ans = max(ans, res);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}