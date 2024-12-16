#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int ans = n - 1;
    
    for (int i = 0; i < n - 1; i++) {
        int res = i;
        int p = a[i] + a[i + 1];
        auto it = lower_bound(a.begin(), a.end(), p);
        int d = a.end() - it;
        res += d;
        ans = min(ans, res);
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