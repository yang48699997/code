#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    if (n == 1 && k == 1) {
        cout << "1\n";
        cout << "1\n";
        return;
    }
    
    if (k == 1 || k == n) {
        cout << "-1\n";
    } else {
        if (k & 1) {
            cout << 3 << "\n";
            cout << 1 << " " << k - 1 << " " << k + 2 << "\n";
        } else {
            cout << 3 << "\n";
            cout << 1 << " " << k << " " << k + 1 << "\n";
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