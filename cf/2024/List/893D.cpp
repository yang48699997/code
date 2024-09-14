#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int r = 0;
    int ans = 0;
    int ok = 1;

    int now = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        int mx = now;
        while (j < n && a[j] != 0) {
            now += a[j];
            mx = max(mx, now);
            r = min(r, d - mx);
            if (mx > d) ok = 0;
            j++;
        }
        if (j < n && a[j] == 0) {
            if (now < 0) {
                if (r + now >= 0) {
                    r += now;
                    now = 0;
                } else {
                    ans++;
                    r = d;
                    now = 0;
                }
            }
        }
        i = j;
    }

    if (ok) cout << ans << "\n";
    else cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}