#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = a / 3 + b / 3 + c / 3 + min({a % 3, b % 3, c % 3});
    if (a >= 3) ans = max(ans, a / 3 - 1 + b / 3 + c / 3 + min({a % 3 + 3, b % 3, c % 3}));
    if (b >= 3) ans = max(ans, a / 3 - 1 + b / 3 + c / 3 + min({a % 3, b % 3 + 3, c % 3}));
    if (c >= 3) ans = max(ans, a / 3 - 1 + b / 3 + c / 3 + min({a % 3, b % 3, c % 3 + 3}));
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}