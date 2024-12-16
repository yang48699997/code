#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    ll n, b, c;
    cin >> n >> b >> c;

    if (b == 0) {
        if (c < n - 2) cout << -1 << "\n";
        else if (c <= n - 1) cout << n - 1 << "\n";
        else cout << n << "\n";
        return;
    }

    __int128 l = 1, r = n;
    while (l <= r) {
        __int128 mid = (l + r) / 2;
        if (mid * b - b + c <= n - 1) l = mid + 1;
        else r = mid - 1;
    }
    
    cout << n - (ll)r << "\n";
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