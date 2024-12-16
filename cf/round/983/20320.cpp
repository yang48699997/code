#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        if (x == 1) cnt++;
    }

    int ans = 0;
    if (cnt <= n) ans = cnt;
    else ans = n * 2 - cnt;

    cout << cnt % 2 << " " << ans << "\n";
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