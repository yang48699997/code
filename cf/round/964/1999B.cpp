#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;
    if (a1 > b1 && a2 > b2) ans++;
    else if (a1 > b1 && a2 == b2) ans++;
    else if (a1 == b1 && a2 > b2) ans++;
    if (a1 > b2 && a2 > b1) ans++;
    else if (a1 > b2 && a2 == b1) ans++;
    else if (a1 == b2 && a2 > b1) ans++;
    if (a2 > b1 && a1 > b2) ans++;
    else if (a2 > b1 && a1 == b2) ans++;
    else if (a2 == b1 && a1 > b2) ans++;
    if (a2 > b2 && a1 > b1) ans++;
    else if (a2 == b2 && a1 > b1) ans++;
    else if (a2 > b2 && a1 == b1) ans++;
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