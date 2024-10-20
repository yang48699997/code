#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<int, int> solve(int n, int m, int xx) {

    auto cal = [&](ll x) -> ll {
        if (x == 0) return 0;
        ll p1 = 2 * (n + m) - 4;
        ll p2 = p1 - (x - 1) * 8;
        return (p1 + p2) / 2 * x;
    };
    
    ll l = 1, r = n / 2;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll res = cal(mid);
        if (res >= xx) r = mid - 1;
        else l = mid + 1;
    }

    ll lef = xx - cal(r);
    ll x = m - 2 * r;
    ll y = n - 2 * r;
    if (x >= lef) {
        return {r + 1, r + lef};
    }
    lef -= x - 1;
    if (y >= lef) {
        return {r + lef, r + x}; 
    }
    lef -= y - 1;
    if (x >= lef) {
        return {n - r, r + x - lef + 1};
    }
    lef -= x - 1;
    return {n - r - lef + 1, r + 1};
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