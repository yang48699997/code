#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];    
    for (int i = 0; i < n; i++) cin >> b[i];    
    sort(a.rbegin(), a.rend());
    int ans = n;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur + a[i] > x) {
            ans = min(ans, i + 1);
            break;
        }
        cur += a[i];
    }
    cur = 0;
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n; i++) {
        if (cur + b[i] > y) {
            ans = min(ans, i + 1);
            break;
        }
        cur += b[i];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}