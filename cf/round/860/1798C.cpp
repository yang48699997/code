#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll x, ll y) {
    while (y) {
        ll t = y;
        y = x % y;
        x = t;
    };
    return x;
};

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    for (int i = 0; i < n; ) {
        ans++;
        ll g1 = a[i] * b[i];
        ll g2 = b[i];
        int j = i + 1;
        for (; j < n; j++) {
            g1 = gcd(g1, a[j] * b[j]);
            g2 = g2 / gcd(g2, b[j]) * b[j];
            if (g1 % g2) break;
        }
        i = j;
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