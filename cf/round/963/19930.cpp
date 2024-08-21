#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(4);
    int l = 0;
    for (int i = 0; i < n * 4; i++) {
        char c;
        cin >> c;
        if (c == '?') {
            l++;
            continue;
        }
        cnt[c - 'A']++;
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int p = min(n, cnt[i]);
        ans += p;
        // if (p < n && l) {
        //     ans += min(n - p, l);
        //     l -= min(n - p, l);
        // }
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