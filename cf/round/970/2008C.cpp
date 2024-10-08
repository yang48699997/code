#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int l, r;
    cin >> l >> r;
    r -= l;
    int ans = sqrt(r * 2);
    if (ans * (ans + 1) > r * 2) ans--;
    cout << ans + 1<< "\n";
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