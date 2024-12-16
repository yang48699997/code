#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> pa(n + 1);
    vector<ll> prea(n + 1);

    vector<ll> c(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        c[i] = c[i + 1] + a[i] * (n - i);
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + c[i];
        pa[i + 1] = pa[i] + a[i] * (n - i);
        prea[i + 1] = prea[i] + a[i];
    }

    int q;
    cin >> q;

    ll tot = 1LL * n * (n + 1) / 2;

    auto get = [&](ll l) -> ll {
        return l * (l + 1) / 2;
    };

    auto cal1 = [&](int l, int r, int i = 0) -> ll {
        ll res = pa[r] - pa[l];
        res -= (prea[r] - prea[l]) * (n - r);
        res += (prea[l] - prea[i]) * (r - l);
        return res;
    };

    auto cal = [&](ll l, ll r) -> ll {
        ll cl = 1, cr = n;
        while (cl <= cr) {
            ll mid = (cl + cr) / 2;
            if (tot - get(n - mid) < l) cl = mid + 1;
            else cr = mid - 1;
        }
        ll pl = cl;

        cl = 1, cr = n;
        while (cl <= cr) {
            ll mid = (cl + cr) / 2;
            if (tot - get(n - mid + 1) >= r) cr = mid - 1;
            else cl = mid + 1;
        }
        ll pr = cr;

        ll p1 = tot - get(n - pl + 1);
        ll p2 = tot - get(n - pr + 1);
        
        if (pl == pr) {
            return cal1(l - p1 + pl - 2, r - p1 + pl - 1, pl - 1);
        } else {
            return cal1(l - p1 + pl - 2, n, pl - 1) + cal1(pr - 1, r - p2 + pr - 1, pr - 1) + pre[pr - 1] - pre[pl];
        }

    };

    while (q--) {
        ll l, r;
        cin >> l >> r;

        cout << cal(l, r) << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}