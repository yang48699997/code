#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, d;
    cin >> n >> d;

    if (n >= 7) {
        for (int i = 1; i <= 9; i += 2) {
            if (i == 5) {
                if (d == 5) cout << 5 << " ";
            } else {
                cout << i << " ";
            }
        }
        cout << "\n";
    } else {
        int p = 1;
        for (int i = 1; i <= n; i++) {
            p *= i;
        }
        for (int i = 1; i <= 9; i += 2) {
            int now = 1;
            int l = 0;
            for (int j = 0; j < p; j++) {
                l += now * d % i;
                now *= 10;
                now %= i;
                l %= i;
            }
            if (l == 0) cout << i << " "; 
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