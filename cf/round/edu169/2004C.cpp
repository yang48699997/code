#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    for (int i = 1; i < n; i += 2) {
        ans += a[i - 1] - a[i] - min(k, a[i - 1] - a[i]);
        k -= min(k, a[i - 1] - a[i]);
    }
    if (n & 1) ans += a.back();
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