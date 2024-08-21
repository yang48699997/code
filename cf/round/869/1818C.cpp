#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> pre(n + 1);
    for (int i = 0; i < n - 2; i++) {
        pre[i + 1] = pre[i];
        if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2]) pre[i + 1]++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = r - l + 1;
        if (l + 2 <= r) ans -= max(0, pre[r - 2] - pre[l - 1]);
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}