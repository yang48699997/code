#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string n;
    cin >> n;
    if (n.length() > 2 && n.substr(0, 2) == "10" ) {
        if (n[2] != '0' && (n[2] != '1' || n.length() > 3)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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