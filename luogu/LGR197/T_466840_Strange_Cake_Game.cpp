#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ll x, y;
        cin >> x >> y;
        if (y >= x) ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}