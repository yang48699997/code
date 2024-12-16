#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << 0 << " " << 0 << " " << min(a, b) << " " << min(a, b) << "\n";
    cout << min(a, b) << " " << 0 << " " << 0 << " " << min(a, b) << "\n";
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