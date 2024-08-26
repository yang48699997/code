#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "0\n";
        return;
    }
    int m = sqrt(n);
    int ans = n - m;
    if (m * m < n) ans--;
    cout << ans << "\n";
    if (n - m * m > m) m++;
    for (int i = 1; i < n; i++) {
        if (i % m == 0) continue;
        cout << i << " " << i + 1 << "\n";
    }
    for (int i = 1; i <= n - m && ans; i++) {
        ans--;
        cout << i << " " << i + m << "\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}