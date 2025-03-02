#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }

    while (a.size() > 1) {
        vector<ll> b;
        ll res = 0;
        for (int i = 1; i < a.size(); i++) {
            b.push_back(a[i] - a[i - 1]);
            res += a[i] - a[i - 1];
        }
        ans = max(ans, abs(res));
        a = b;
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