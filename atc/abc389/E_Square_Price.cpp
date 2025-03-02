#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 0, r = m;
    while (l <= r) {
        ll mid = (l + r) / 2;
        __int128 tot = 0;
        for (int i = 0; i < n && tot <= m; i++) {
            __int128 p = mid / a[i];
            p = (p + 1) / 2;
            if ((2 * p - 1) * a[i] == mid) p--;
            tot += p * p * a[i];
        }
        if (tot > m) r = mid - 1;
        else l = mid + 1;
    }

    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        ll p = r / a[i];
        p = (p + 1) / 2;
        if ((2 * p - 1) * a[i] == r) {
            p--;
            cnt++;
        }
        m -= p * p * a[i];
        ans += p;
    }

    ans += min(cnt, m / r);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}