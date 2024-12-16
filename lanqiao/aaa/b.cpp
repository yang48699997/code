#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    
    ll x = n / k;
    ll y = m / k;

    ll ans = 0;
    if (x == 0 || y == 0) {

    } else if (x == 1) {
        ans = y;
    } else {
        if (y == 1) ans = x;
        else ans = x * 2 + y * 2 - 4;
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