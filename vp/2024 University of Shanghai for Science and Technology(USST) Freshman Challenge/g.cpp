#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int x, k;
    cin >> x >> k;
    int ok = 1;
    while (k > 0) {
        if (x == k) ok = 0;
        k = k / 2 + k % 2 - 1;
    }
    if (ok) cout << "Alice\n";
    else cout << "Bob\n";
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