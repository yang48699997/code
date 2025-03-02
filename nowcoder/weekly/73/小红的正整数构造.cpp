#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int l, r, x;
    cin >> l >> r >> x;

    int ans = (l - 1) / x * x + x;
    if (ans > r) cout << "-1\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}