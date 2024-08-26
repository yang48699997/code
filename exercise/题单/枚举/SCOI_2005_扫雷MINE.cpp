#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    vector<int> dp1(1 << 3);
    vector<int> dp2(1 << 3);
    for (int i = 0; i < 1 << 3; i++) {
        if (a[0] == __builtin_popcount(i >> 1) && a[1] == __builtin_popcount(i)) dp1[i] = 1;
    }
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < 1 << 3; j++) dp2[j] = 0;
        for (int j = 0; j < 1 << 3; j++) {
            int nxt = (j << 1 & 7);
            int cnt = __builtin_popcount(nxt);
            if (cnt == a[i]) dp2[nxt] += dp1[j];
            if (cnt == a[i] - 1) dp2[nxt | 1] += dp1[j];
        }
        for (int j = 0; j < 1 << 3; j++) dp1[j] = dp2[j];
    }
    int ans = 0;
    for (int i = 0; i < 1 << 3; i += 2) {
        if (__builtin_popcount(i >> 1) == a.back()) ans += dp1[i];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}