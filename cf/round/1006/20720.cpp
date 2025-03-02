#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    k = abs(k);
    int ans = (k - 1) / x + 1;
    if (k == 0) ans = 0;

    if (ans > n) cout << "-1\n";
    else cout << ans << "\n";
    
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