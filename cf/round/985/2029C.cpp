#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    const int inf = 1e9;
    int dp0 = -inf, dp1 = 0, dp2 = -inf;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int nxt = dp1;
        if (x > dp1) nxt++;
        else if (x < dp1) nxt--;

        dp0 = max(dp0, dp1);
        dp1 = nxt;
        if (dp2 < x) {
            dp2 = max(dp0, dp2 + 1);
        } else if (dp2 == x) {
            dp2 = max(dp0, dp2);
        } else {
            dp2 = max(dp0, dp2 - 1);
        }

    }

    cout << dp2 << "\n";
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