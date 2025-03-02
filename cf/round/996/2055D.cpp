#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k, l;
    cin >> n >> k >> l;

    k *= 2;
    l *= 2;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= 2;
    }

    int ans = a[0];

    int now = k;

    for (int i = 1; i < n && now < l; i++) {
        int cl = a[i] - ans;
        int cr = a[i] + ans;
        if (cl > now) {
            ans += (cl - now) / 2;
            now = (now + cl) / 2 + k;
        } else if (cr < now) {
            now = max(now, cr + k);
        } else {
            now += k;
        }
    }

    if (now < l) ans += l - now;

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