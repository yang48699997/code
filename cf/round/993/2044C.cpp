#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;

    int d1 = min(a, m);
    int d2 = min(b, m);

    int ans = d1 + d2;
    int p = min(m - d1, c);
    ans += p;
    c -= p;
    ans += min(m - d2, c);

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