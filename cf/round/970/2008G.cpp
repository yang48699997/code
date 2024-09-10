#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        int ans = k - 1;
        if (a[0] < k) ans++;
        cout << ans << "\n";
        return;
    }
    int g = a[0];
    for (int i = 1; i < n; i++) {
        g = __gcd(g, a[i]);
    }
    int p = g - 1;
    int ans = 0;
    if (p == 0) ans = n + k - 1;
    else {
        k--;
        ans = min(k / p, n);
        k -= ans * p;
        if (n > ans) k++;
        ans = ans * g;
        ans += k;
    }
    cout << ans << "\n";
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