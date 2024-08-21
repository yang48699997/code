#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        deg[x]++;
        deg[y]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) ans++;
    }

    cout << ans / 2 + ans % 2 << "\n";
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