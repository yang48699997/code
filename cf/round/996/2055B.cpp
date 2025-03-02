#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> d(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] <= a[i]) continue;
        d[0] += b[i] - a[i];
        d[i] -= b[i] - a[i];
        d[i + 1] += b[i] - a[i];
    }

    for (int i = 1; i < n; i++) {
        d[i] += d[i - 1];
    }

    for (int i = 0; i < n; i++) {
        if (d[i] == 0) continue;
        if (max(a[i] - b[i], 0) < d[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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