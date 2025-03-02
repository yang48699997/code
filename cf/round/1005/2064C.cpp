#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    vector<ll> r(n + 1);

    for (int i = n - 1; i >= 0; i--) {
        r[i] = r[i + 1];
        if (a[i] < 0) r[i] -= a[i];
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, res + r[i]);
        if (a[i] > 0) res += a[i];
    }

    cout << max(ans, res) << "\n";
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