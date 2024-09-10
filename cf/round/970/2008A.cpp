#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a & 1) {
        cout << "NO\n";
        return;
    }
    if (b & 1) {
        if (a >= 2) {
            cout << "YES\n";
        } else cout << "NO\n";
        return;
    }
    cout << "YES\n";
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