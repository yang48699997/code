#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int x;
    cin >> x;

    ll p = 1;
    while (x) {
        p *= 10;
        x /= 10;
    }

    cout << p + 1 << "\n";
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