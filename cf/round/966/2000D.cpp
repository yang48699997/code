#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i];
        pre[i + 1] += a[i];
    }
    ll ans = 0;
    int l = 0, r = n - 1;

    while (l < r) {
        while (l < n && s[l] == 'R') l++;
        while (r >= 0 && s[r] == 'L') r--;
        if (l > r) break;
        ans += pre[r + 1] - pre[l];
        l++;
        r--;
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