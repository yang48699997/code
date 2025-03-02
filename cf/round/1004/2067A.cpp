#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int x, y;
    cin >> x >> y;

    if (x + 1 < y || (x + 1 - y) % 9 != 0) cout << "No\n";
    else cout << "Yes\n";
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