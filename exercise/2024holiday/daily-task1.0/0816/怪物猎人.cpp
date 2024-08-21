#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll k, x, y;
    cin >> k >> x >> y;
    if (x < y) swap(x, y);
    vector<int> ok(2);
    ll t = (k - 1) / x + 1;
    ok[t & 1] = 1;
    ll t2 = (k - 1) / y + 1;
    if (t2 != t) ok[t & 1 ^ 1] = 1;

    if (ok[1]) cout << "Yes\n";
    else cout << "No\n";
    if (ok[0]) cout << "Yes\n";
    else cout << "No\n";
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