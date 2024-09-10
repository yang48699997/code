#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int t1 = x / k;
    int t2 = y / k;
    if (x % k) t1++;
    if (y % k) t2++;
    int ans = max(t1, t2) * 2;
    if (t1 > t2) ans--;
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