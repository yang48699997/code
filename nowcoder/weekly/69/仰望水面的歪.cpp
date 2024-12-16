#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int q;
    cin >> q;

    ll h;
    cin >> h;

    while (q--) {
        ll x, y, z;
        cin >> x >> y >> z;
        z = h * 2 - z;

        ll g = __gcd(__gcd(x, y), z);

        cout << x / g << " " << y / g << " " << z / g << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}