#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    ll p = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == p) ans++;
        else {
            if ((a[i] - p) * (n - i) >= k) {
                ans += k;
                break;
            } else {
                ans += (a[i] - p) * (n - i) + 1;
                k -= (a[i] - p) * (n - i);
                p = a[i];
            }
        }
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