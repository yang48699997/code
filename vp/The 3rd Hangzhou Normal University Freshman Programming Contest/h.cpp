#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    cout << "[";
    for (int i = 1; i <= n; i++) {
        if (i <= m) cout << "#";
        else cout << "-";
    }
    int res = m * 100 / n;
    cout << "] " << res << "%" << "\n";
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