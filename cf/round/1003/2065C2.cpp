#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());

    int pre = -1e9;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i] + pre);
        if (it == b.end()) {
            if (a[i] < pre) {
                cout << "NO\n";
                return;
            } else {
                pre = a[i];
                continue;
            }
        }

        if (a[i] < pre) pre = *it - a[i];
        else pre = min(a[i], *it - a[i]);
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