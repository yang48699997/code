#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int x;
    cin >> x;

    int ok = 1;
    for (int i = 1; i < n; i++) {
        int y;
        cin >> y;
        if (abs(x - y) != 7 && abs(x - y) != 5) ok = 0;
        x = y;
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";
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