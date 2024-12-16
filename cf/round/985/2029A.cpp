#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll l, r, k;
    cin >> l >> r >> k;

    ll cl = l, cr = r;
    while (cl <= cr) {
        ll mid = (cl + cr) / 2;
        if (mid * k > r) cr = mid - 1;
        else cl = mid + 1;
    }

    cout << cl - l << "\n";
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