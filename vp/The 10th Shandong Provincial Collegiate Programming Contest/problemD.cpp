#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == a.back()) {
        cout << "0\n";
        return;
    }

    ll ans = sum;
    int cnt = 0;
    ll tot = 0;
    cnt++;
    tot += a.back();
    sum -= a.back();
    for (int i = n - 2; i >= 0; i--) {
        ll res = tot - cnt * a[i];
        if (a[i] * (n - cnt) - sum <= res) {
            ll lef = res + sum - a[i] * (n - cnt);
            ans = min(ans, res - min(a[i + 1] - a[i], lef / n) * cnt);
        }
        tot += a[i];
        sum -= a[i];
        cnt++;
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