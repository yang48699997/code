#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int m, k, h;
    cin >> m >> k >> h;

    auto check =  [&](int x) -> int {
        if (x >= h) return 1;
        if (m == k && x >= m) return 1;
        if (x < m) return 0;
        int d = m - k;
        ll sum = x;
        ll t = (x - m) / d + 1;
        sum += t * k;
        return sum >= h;
    };

    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    } 
    cout << l << "\n";
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