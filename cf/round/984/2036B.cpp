#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> cnt(k + 1);
    for (int i = 0; i < k; i++) {
        int b, c;
        cin >> b >> c;
        cnt[b] += c;
    }

    sort(cnt.rbegin(), cnt.rend());
    int ans = 0;
    for (int i = 0; i < min(n, k); i++) {
        ans += cnt[i];
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