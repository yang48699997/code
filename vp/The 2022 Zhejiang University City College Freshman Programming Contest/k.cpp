#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> to(2, vector<int> (30));
    for (int i = 0; i < 30; i++) {
        to[1][i] = 1;
    }
    while (n--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == '1') {
            for (int i = 0; i < 30; i++) {
                int p = x & 1;
                x >>= 1;
                to[0][i] = (to[0][i] & p);
                to[1][i] = (to[1][i] & p);
            }
        } else if (op == '2') {
            for (int i = 0; i < 30; i++) {
                int p = x & 1;
                x >>= 1;
                to[0][i] = (to[0][i] | p);
                to[1][i] = (to[1][i] | p);
            }
        } else {
            for (int i = 0; i < 30; i++) {
                int p = x & 1;
                x >>= 1;
                to[0][i] = (to[0][i] ^ p);
                to[1][i] = (to[1][i] ^ p);
            }
        }
    }

    while (q--) {
        int x;
        cin >> x;
        vector<int> p(30);
        for (int i = 0; i < 30; i++) {
            p[i] = x & 1;
            x >>= 1;
        }
        int ans = 0;
        int ok = 0;
        for (int i = 29; i >= 0; i--) {
            if (to[0][i] >= to[1][i]) {
                if (p[i] == 1) ok = 1;
            } else {
                if (ok || p[i] == 1) {
                    ans |= 1 << i;
                }
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}