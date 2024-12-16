#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k, h;
    ll l, r;
    cin >> n >> k >> h >> l >> r;

    if (l >= 0 || -l * k < h || h + r * k < 0) {
        cout << "impossible\n";
        return;
    } 

    ll lef = -l * k - h;
    for (int i = 0; i < n; i++) {
        ll now = min(lef, r - l);
        cout << l + now << " \n"[i == n - 1];
        lef -= now;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}