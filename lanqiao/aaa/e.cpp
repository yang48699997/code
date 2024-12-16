#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (i & 1) continue;
        ans += x * (n - i);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}