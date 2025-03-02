#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    int ans = 0;
    vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] & 1]++;
    }

    if (cnt[0]) {
        ans++;
        cnt[0]--;
    } else {
        cnt[1]--;
    }

    ans += cnt[1];

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