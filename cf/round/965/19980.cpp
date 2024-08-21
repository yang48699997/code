#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    if (k % 2 == 1) {
        cout << x << " " << y << "\n";
        k--;
    }
    int d = 1;
    for (int i = 0; i < k; i += 2) {
        cout << x - d << " " << y << "\n";
        cout << x + d << " " << y << "\n";
        d++;
    }
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