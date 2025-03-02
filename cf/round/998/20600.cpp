#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    vector<int> a(4);
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    int a1 = a[0] + a[1];
    int a2 = a[2] - a[1];
    int a3 = a[3] - a[2];

    map<int, int> cnt;
    int ans = 0;
    ans = max(++cnt[a1], ans);
    ans = max(++cnt[a2], ans);
    ans = max(++cnt[a3], ans);

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