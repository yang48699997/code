#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const double eps = 1e-7;
const double mx = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> p;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        p.push_back({x, y, z});
    }
    double ans = mx;
    auto cal = [&](int t) -> void {
        double l = 0, r = mx;
        while (r - l >= eps) {
            double mid = (l + r) / 2;
            vector<pair<double, int>> dif;
            for (int i = 0; i < n; i++) {
                double now = mid * mid;
                double s = 0;
                for (int j = 0; j < 3; j++) {
                    if (j == t) {
                        s = p[i][j]; 
                        continue;
                    }
                    now -= p[i][j] * p[i][j];
                }
                if (now < 0) continue;
                now = sqrt(now);
                dif.emplace_back(s - now, 1);
                dif.emplace_back(s + now + eps, -1);
            }
            sort(dif.begin(), dif.end());
            int cnt = 0;
            int ok = 0;
            for (int i = 0; i < dif.size(); i++) {
                cnt += dif[i].second;
                if (cnt >= n / 2) ok = 1;
            }
            if (ok) r = mid;
            else l = mid;
        }
        ans = min(ans, l);
    };
    for (int i = 0; i < 3; i++) cal(i);
    cout << fixed << setprecision(8) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}