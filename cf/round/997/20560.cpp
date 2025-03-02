#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = m * 4;

    int a, b;
    cin >> a >> b;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;

        ans -= (m * 2 - x - y) * 2;
        ans += m * 4;
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