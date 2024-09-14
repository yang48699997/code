#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll dp1 = 0, dp2 = -1e18;
    vector<int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        ll p = abs(a[i] - a[i - 1]);
        ll tmp1 = dp1, tmp2 = dp2;
        dp1 = max(tmp2 + p, p);
        dp2 = tmp1 - p;
        ans = max({dp1, dp2, ans});
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}