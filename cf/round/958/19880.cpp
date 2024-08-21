#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (n > 1) {
        n -= k - 1;
        ans++;
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