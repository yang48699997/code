#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int x : a) {
        int now = 0;
        int l = 0, r = 0;
        while (r < n) {
            while (r < n && now < x) {
                now += a[r++];
            }
            while (l < r && now - a[l] >= x) {
                now -= a[l++];
            }
            if (now == x && r - l > 1) {
                ans++;
                break;
            }
            now -= a[l++];
        }
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