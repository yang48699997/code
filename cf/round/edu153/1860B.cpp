#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    m -= min(m / k, ak) * k;
    int ans = 0;
    int l = m % k;
    ans += max(0, l - a1);
    a1 -= min(l, a1);
    m -= l;
    m -= min(a1 / k, m / k) * k;
    ans += m / k;
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