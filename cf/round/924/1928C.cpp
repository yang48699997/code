#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, x;
    cin >> n >> x;
    int ans = 0;
    int p = n - x;
    for (int i = 1; i <= sqrt(p); i++) {
        if (p % i) continue;
        int a = p / i, b = i;
        if (a % 2 == 0 && (a / 2 + 1) >= x && (a / 2 + 1) > 1) {
            ans++;
            if (a == b) ans--;
        }
        if (b % 2 == 0 && b / 2 + 1>= x && b / 2 + 1 > 1) ans++;
    }
    if (x == 1) {
        cout << ans << "\n";
        return;
    }
    p = n + x - 2;
    for (int i = 1; i <= sqrt(p); i++) {
        if (p % i) continue;
        int a = p / i, b = i;
        if (a % 2 == 0 && (a / 2 + 1) >= x && (a / 2 + 1) > x) {
            ans++;
            if (a == b) ans--;
        }
        if (b % 2 == 0 && b / 2 + 1>= x && b / 2 + 1 > x) ans++;
    }
    cout << ans << "\n";
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