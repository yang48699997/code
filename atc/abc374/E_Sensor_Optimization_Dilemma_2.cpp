#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
        if (a[i] * q[i] > b[i] * p[i]) {
            swap(a[i], b[i]);
            swap(q[i], p[i]);
        }
    }

    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ll res = 1e9;
            for (int j = 0; j <= b[i]; j++) {
                ll now = j * p[i];
                ll lef = max(0, mid - j * a[i]);
                if (lef > 0) {
                    now += (lef - 1) / b[i] * q[i] + q[i];
                }
                res = min(res, now);
            }
            sum += res;
        }
        if (sum <= x) l = mid + 1;
        else r = mid - 1;
    }
    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}