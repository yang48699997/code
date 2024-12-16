#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << "1\n";
        return;
    }
    
    if (n & 1) {
        ll ans = 1e18;
        for (int i = 0; i < n; i++) {
            ll res = 1;
            ll now = a[i] + 1;
            for (int j = i + 1; j < n && a[j] == now; j++) {
                now++;
            }
            res = now - a[i];
            now = a[i] - 1;
            for (int j = i - 1; j >= 0 && a[j] == now; j--) {
                now--;
            }
            res = min(res, a[i] - now);
            for (int j = 0; j < n;) {
                if (j == i) {
                    j++;
                } else if (j == i - 1) {
                    res = max(res, a[j + 2] - a[j]);
                    j = j + 3;
                } else {
                    res = max(res, a[j + 1] - a[j]);
                    j = j + 2;
                }
            }

            ans = min(ans, res);
        }

        cout << ans << "\n";
    } else {
        ll ans = 1;
        for (int i = 1; i < n; i += 2) {
            ans = max(ans, a[i] - a[i - 1]);
        }

        cout << ans << "\n";
    }
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