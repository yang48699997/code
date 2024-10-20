#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n & 1) {
        if (k & 1) {
            if (n >= k) {
                cout << "YES\n";
                for (int i = 0; i < k - 1; i++) {
                    cout << 1 << " ";
                }
                cout << n - k + 1 << "\n";
                return;
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            cout << "NO\n";
            return;
        }
    } else {
        if (k % 2 == 0) {
            if (k <= n) {
                cout << "YES\n";
                for (int i = 0; i < k - 1; i++) {
                    cout << 1 << " ";
                }
                cout << n - k + 1 << "\n";
                return;
            }
        }
        if (k * 2 > n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++) {
                cout << 2 << " ";
            }
            cout << n - k * 2 + 2 << "\n";
            return;
        }
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