#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1, -1);

    for (int i = y; i <= x; i++) a[i] = 1;
    for (int i = x + 2; i <= n; i += 2) a[i] = 1;
    for (int i = y - 2; i > 0; i -= 2) a[i] = 1;

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
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