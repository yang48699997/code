#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (4 * a * a <= 3 * b * b) {
        double ans = a;
        ans = 2 * ans * sqrt(3.0) / 3;
        cout << fixed << setprecision(10) << ans;
    } else {
        double ans = 0;
        ans = 2 * sqrt(a * a + b* b - sqrt(3.0) * a * b);
        cout << fixed << setprecision(10) << ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}