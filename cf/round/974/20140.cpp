#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int now = 0;
    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0 && now) now--, ans++;
        else if (x >= k) now += x;
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