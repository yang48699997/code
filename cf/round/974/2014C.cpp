#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    vector<ll> b;
    int ok = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (!ok && a[i] == mx) {
            ok = 1;
        } else b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    ll l = 0, r = 1e18;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll tar = sum + mid;
        if (tar % (n * 2) == 0) tar /= (n * 2);
        else {
            tar /= (n * 2);
            tar++;
        }
        auto it = lower_bound(b.begin(), b.end(), tar);
        int p = it - b.begin();
        if (p > n / 2) r = mid - 1;
        else l = mid + 1; 
    }
    if (r == 1e18) cout << -1 << "\n";
    else cout << l << "\n";
    
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