#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int T;
void solve() {
    int n, k;
    cin >> n >> k;
    k = min(k, n - k);
    if (n % 2 == 0 && n / 2 == k) {
        cout << n << "\n";
    } else {
        ll ans = n;
        ans *= k;
        ans++;
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}