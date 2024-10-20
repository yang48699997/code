#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << -1 << "\n";
        return;
    }
    if (n & 1) {
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        n--;
        cout << n - 2 << " " << n;
        for (int i = n - 4; i >= 2; i -= 2) {
            cout << " " << i;
        }
        cout << "\n";
    } else {
        for (int i = n - 1; i >= 1; i -= 2) {
            cout << i << " ";
        }
        cout << 4 << " " << 2;
        for (int i = 6; i <= n; i += 2) {
            cout << " " << i;
        }
        cout << "\n";
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