#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const double PI = acos(-1);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<double> c;

    for (int i = 0; i < n; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        double p = sqrt(x * x + y * y);
        if (p >= r) {
            c.push_back(0);
            continue;
        }
        c.push_back((r - p) * r * PI * r);
    }    
    
    k = n - k;
    sort(c.begin(), c.end());
    double ans = 0;
    while (k--) {
        ans += c[k];
    }
    cout << fixed << setprecision(8) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}