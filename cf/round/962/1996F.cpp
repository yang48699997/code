#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll inf = 1e18;
int T;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int l = 0, r = 1e9;
    auto cal = [&](int p) -> ll {
        if (p == 0) {
            return inf;
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < p) continue; 
            res += (a[i] - p) / b[i] + 1;
        }
        return res;
    };

    ll ans = 0;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        ll res = cal(mid);
        if (res >= k) l = mid + 1;
        else r = mid - 1;
    }

    l--;
    for (int i = 0; i < n; i++) {
        if (a[i] <= l) continue;
        int c = (a[i] - l) / b[i];
        ll mx = a[i], mi = a[i] - c * b[i];
        if (mi == l) {
            mi += b[i];
        } else c++;
        k -= c;
        ans += (mx + mi) * c / 2;
    }
    ans += k * (ll)l;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}