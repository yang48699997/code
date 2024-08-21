#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double d1 = (x1 - x2) * (x1 - x2) + (y1 + y2) * (y1 + y2);
    double d2 = (x1 + x2) * (x1 + x2) + (y1 - y2) * (y1 - y2);
    d1 = sqrt(d1);
    d2 = sqrt(d2);
    double d = min(d1, d2);
    cout << fixed << setprecision(10) << d << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}