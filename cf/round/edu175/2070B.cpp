#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x;
    ll k;
    cin >> n >> x >> k;

    string s;
    cin >> s;

    ll ans = 0;

    int l = 0;
    while (k && x && l < n) {
        if (s[l++] == 'L') x--;
        else x++;
        k--;
        if (x == 0) ans++;
    }

    if (x != 0) {
        cout << "0\n";
        return;
    }

    int p = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') p--;
        else p++;
        cnt++;
        if (p == 0) break;
    }

    if (p == 0) ans += k / cnt;

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