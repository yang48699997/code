#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n = 5;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    ll p = min(a[0], a[4]);
    ans += p;
    a[0] -= p;
    a[4] -= p;
    ans += a[2] / 2;
    a[2] %= 2;
    p = min(a[1], a[3]);
    ans += p;
    a[1] -= p;
    a[3] -= p;
    
    if (a[0]) {
        if (a[1]) {
            if (a[2]) {

            } else {
                
            }
        } else if (a[2]) {

        }
    } else if (a[1]) {
        if (a[2]) {

        } else {

        }
    } else {
        p = min(a[3] + a[2], a[4]);
        ans += p;
        ans += (a[2] + a[3] + a[4] - p * 2) / 6;
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