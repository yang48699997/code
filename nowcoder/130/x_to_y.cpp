#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x, y;
    cin >> x >> y;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 60; i++) {
        int p1 = (x & 1);
        int p2 = (y & 1);
        x >>= 1;
        y >>= 1;
        if (p1 && p2) {
            continue;
        } else if (p1) {
            cnt1 = 1;
        } else if (p2) {
            cnt2 = 1;
        }
    }

    cout << cnt1 + cnt2 << "\n";
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