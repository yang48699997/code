#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
    }
    while (q--) {
        char c;
        cin >> c;
        int l, r;
        cin >> l >> r;
        if (mx < l || mx > r) {
            cout << mx << " \n"[q == 0];
            continue;
        }
        if (c == '-') {
            mx--;
        } else {
            mx++;
        }
        cout << mx << " \n"[q == 0];
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