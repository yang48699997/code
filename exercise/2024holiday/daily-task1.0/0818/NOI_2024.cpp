#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a - 1;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
    }
    if (k == m) {
        cout << "YES\n";
        return;
    }
    if (sum < k) cout << "YES\n";
    else cout << "NO\n";
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