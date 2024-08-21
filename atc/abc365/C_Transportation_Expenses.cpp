#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<int> a(n + 1);
    ll sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    
    ll ans = min(sum, m) / n;
    ll res = 0;
    sort(a.begin(), a.end() - 1);
    for (int i = 1; i <= n; i++) {
        res += a[i - 1];
        sum -= a[i - 1];
        if (res > m) break;
        if (i == n) {
            ans = 1e18;
            break;
        }
        ll p = min(sum, m - res) / (n - i);
        if (p >= a[i - 1]) ans = max(ans, p);
    }

    if (ans >= a[n - 1]) cout << "infinite\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}