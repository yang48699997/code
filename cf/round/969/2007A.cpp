#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int l, r;
    cin >> l >> r;
    if (l & 1) l--;
    cout << (r - l + 1) / 4 << "\n";
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