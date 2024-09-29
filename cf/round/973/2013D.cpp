#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e12;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    ll mi = inf;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mi = min(mi, sum / (i + 1));
    }
    ll l = 0, r = inf;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll lef = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mi + mid) {
                lef += a[i] - mi - mid;
            } else {
                lef -= min(lef, mi + mid - a[i]);
            }
        }
        if (lef <= 0) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << "\n";
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