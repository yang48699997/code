#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if (abs(a - b) & 1) cout << "NO\n";
    else cout << "YES\n";
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