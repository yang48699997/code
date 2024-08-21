#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll l, x, y;
    cin >> l >> x >> y;
    if (l * l >= x * x + y * y) {
        cout << "Yes\n";
        cout << "0\n";
        return;
    } else if (l * l >= (x - l) * (x - l) + y * y) {
        cout << "Yes\n";
        cout << l << "\n";
        return;
    } else cout << "No\n";
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