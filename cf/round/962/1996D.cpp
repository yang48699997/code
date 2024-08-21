#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n, x;
    cin >> n >> x;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i * j >= n) break;
            int l1 = n - i * j; 
            int l2 = x - i - j;
            ans += max (0, min(l1 / (i + j), l2));
        }
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