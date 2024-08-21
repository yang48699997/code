#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, k;
    cin >> n >> k;
    int ok = -1;
    for (int i = 0; i < n; i++) {
        int cnt = i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2;
        if (cnt == k) {
            ok = i;
            break;
        }
    }
    if (ok == -1) {
        cout << "NO\n";
        return;
    } else cout << "YES\n";
    for (int i = 0; i < ok; i++) {
        cout << 1 << " ";
    }
    for (int i = ok; i < n; i++) {
        cout << "-1 ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}