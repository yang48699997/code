#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    int l = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m) break;
        while (l < i && (a[i] - a[l] > 1 || res + a[i] > m)) res -= a[l++];
        res += a[i];
        ans = max(ans, res);
    }    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}