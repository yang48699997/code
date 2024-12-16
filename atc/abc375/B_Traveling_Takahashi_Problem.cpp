#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    double ans = 0;
    ll x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        ll nx, ny;
        cin >> nx >> ny;
        ans += sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
        x = nx;
        y = ny;
    }

    ans += sqrt(x * x + y * y);

    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}