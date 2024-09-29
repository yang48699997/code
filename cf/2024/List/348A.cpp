#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll p = 0;
    for (int i = 0; i < n; i++) {
        p = max(a[i], p);
    }
    ll res = 0;
    for (int i = 0; i < n; i++) res += p - a[i];
    if (res >= p) cout << p << "\n";
    else cout << p + (p - res - 1) / (n - 1) + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}