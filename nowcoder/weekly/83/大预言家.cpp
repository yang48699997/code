#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x;
    cin >> x;

    if (x == 1) {
        cout << "0 0\n";
        return;
    }

    auto cal = [](ll p) -> ll {
        return p + p * (p - 1) * 4 + 1;
    };

    ll l = 0, r = 1e9;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (cal(mid) > x) r = mid - 1;
        else l = mid + 1;
    }

    x -= cal(r);
    ll tx = r, ty = 0;
    if (x) {
        ll p = min(r, x);
        ty -= p;
        x -= p;
    }
    if (x) {
        ll p = min(x, 2 * r);
        tx -= p;
        x -= p;
    }
    if (x) {
        ll p = min(x, 2 * r);
        ty += p;
        x -= p;
    }
    if (x) {
        ll p = min(x, 2 * r + 1);
        tx += p;
        x -= p;
    }
    if (x) {
        ll p = min(x, r + 1);
        ty -= p;
        x -= p;
    }
    cout << tx << " " << ty << "\n";

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