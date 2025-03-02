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

    vector<ll> p = a;
    sort(p.begin(), p.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sum -= p[i];
        ans += p[i] * (n - i - 1) + sum;

        auto it = lower_bound(p.begin(), p.end(), 100000000 - p[i]);
        int pos = it - p.begin();
        pos = max(pos, i + 1);
        ans -= 100000000LL * (n - pos);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}