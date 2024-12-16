#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ans = b * c;
    if (ans % d == 0) {
        ans /= d;
        ans--;
    } else {
        ans /= d;
    }
    cout << a - ans << " ";
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