#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    vector<int> pre(n), suf(n);
    pre[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        pre[i + 1] = pre[i];
        if (i + a[i] > pre[i] + a[pre[i]]) pre[i + 1] = i;
    }
    suf[n - 1] = n - 1;
    for (int i = n - 1; i > 0; i--) {
        suf[i - 1] = suf[i];
        if (a[i] - i > a[suf[i]] - suf[i]) suf[i - 1] = i;
    }
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, a[i] + a[pre[i]] + a[suf[i]] - suf[i] + pre[i]);
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