#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, s, m;
    cin >> n >> s >> m;
    int l = 0;
    int ok = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x - l >= s) {
            ok = 1;
        }
        l = y;
    }
    if (m - l >= s) ok = 1;
    if (ok) cout << "YES\n";
    else cout << "NO\n";
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