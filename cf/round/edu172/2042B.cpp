#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        cnt[x]++;
    }

    int p = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) continue;
        else if (cnt[i] == 1) p++;
        else ans++;
    }

    ans += (p + 1) / 2 * 2;

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