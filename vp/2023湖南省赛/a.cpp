#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    ll l = 0, r = n;
    while (l <= r) {
        ll mid = l + r >> 1;
        ll lef = (n - mid) * (n - mid + 1) / 2 - mid;
        if (lef > m) l = mid + 1;
        else r = mid - 1;
    }
    cout << l << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}