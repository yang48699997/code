#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    double s, t;
    cin >> s >> t;
    vector<pair<double, double>> p1, p2;
    for (int i = 0; i < n; i++) {
        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        p1.emplace_back(x1, y1);
        p2.emplace_back(x2, y2);
    }

    double ans = 1e18;
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);

    auto dfs = [&](auto &&self, int i, double px, double py, double res, int pre) -> void {
        if (i == n) {
            ans = min(ans, res);
            return;
        }
        double d1 = (px - p1[nums[i]].first) * (px - p1[nums[i]].first) + (py - p1[nums[i]].second) * (py - p1[nums[i]].second);
        d1 = sqrt(d1) / s;
        double d2 = (px - p2[nums[i]].first) * (px - p2[nums[i]].first) + (py - p2[nums[i]].second) * (py - p2[nums[i]].second);
        d2 = sqrt(d2) / s;
        double d = (p2[nums[i]].first - p1[nums[i]].first) * (p2[nums[i]].first - p1[nums[i]].first) + (p2[nums[i]].second - p1[nums[i]].second) * (p2[nums[i]].second - p1[nums[i]].second);
        d = sqrt(d) / t;
        self(self, i + 1, p2[nums[i]].first, p2[nums[i]].second, res + d1 + d, nums[i]);
        self(self, i + 1, p1[nums[i]].first, p1[nums[i]].second, res + d2 + d, nums[i]);
    };
    do {
        dfs(dfs, 0, 0, 0, 0, -1);
    } while (next_permutation(nums.begin(), nums.end()));
    
    cout << fixed << setprecision(8) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}