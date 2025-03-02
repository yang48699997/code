#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    if (k > max(n, m) || k < abs(n - m)) {
        cout << "-1\n";
        return;
    }

    int p = 0;
    if (m > n) p = 1;

    int lef = max(n, m) - k;

    for (int i = 0; i < max(n, m); i++) {
        cout << p;
        if (lef) {
            cout << (p ^ 1);
            lef--;
        }
    }
    for (int i = 0; i < min(n, m) - max(n, m) + k; i++) {
        cout << (p ^ 1);
    }

    cout << "\n";
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