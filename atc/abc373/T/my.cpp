#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    vector<ll> p = a;
    sort(p.begin(), p.end());
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + p[i];
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        ll l = 0, r = k;
        int ok = 0;
        while (l <= r) {
            ok = 0;
            ll mid = (l + r) / 2;
            int pos = upper_bound(p.begin(), p.end(), a[i] + mid) - p.begin();
            int now = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
            int lef = n - pos;
            lef = m - lef;
            if (lef <= 0) ok = 1;
            else if (pos - now - 1>= lef) {
                ll res = pre[pos] - pre[pos - lef];
                if (res + k - mid >= (a[i] + mid + 1) * lef) ok = 1;
            } else {
                int len = lef;
                ll res = pre[pos] - pre[now + 1];
                lef -= pos - now - 1;
                res += pre[now] - pre[now - lef];
                if (res + k - mid >= (a[i] + mid + 1) * len) ok = 1;
            }
            if (ok) l = mid + 1;
            else r = mid - 1;
        }
        if (l != k + 1) ans[i] = l;
        else ans[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}