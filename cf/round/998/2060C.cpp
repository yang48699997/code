#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int p = k - i;
        if (p == i) ans += cnt[i] / 2;
        else if (p <= n && p > 0) {
            ans += min(cnt[i], cnt[p]);
            cnt[p] = 0;
        }
    }

    ans = min(ans, n / 2);

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