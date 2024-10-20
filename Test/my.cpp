#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
map<string, double> mp = {
    {"A", 1.0},
    {"2", 2.0},
    {"3", 3.0},
    {"4", 4.0},
    {"5", 5.0},
    {"6", 6.0},
    {"7", 7.0},
    {"8", 8.0},
    {"9", 9.0},
    {"10", 10.0},
    {"J", 11.0},
    {"Q", 12.0},
    {"K", 13.0},
};

void solve(){
    vector<string> a(4);
    for (int i = 0; i < 4; i++) cin >> a[i];
    vector<double> nums(4);
    for (int i = 0; i < 4; i++) nums[i] = mp[a[i]];

    int ok = 0;

    sort(nums.begin(), nums.end());
    auto dfs = [&](auto &&self, int i, double pre) -> void {
        if (ok == 1) return;
        if (i == 4) {
            if (fabs(pre - 24) <= eps) {
                ok = 1;
            }
            return; 
        }
        self(self, i + 1, pre + nums[i]);
        self(self, i + 1, pre * nums[i]);
        self(self, i + 1, pre - nums[i]);
        self(self, i + 1, nums[i] - pre);
        self(self, i + 1, pre / nums[i]);
        if (fabs(pre) > eps) self(self, i + 1, nums[i] / pre);
        if (i == 2) {
            if (fabs(pre * (nums[i] + nums[i + 1]) - 24) <= eps) ok = 1;
            if (fabs(pre + (nums[i] * nums[i + 1]) - 24) <= eps) ok = 1;
            if (fabs(pre - (nums[i] * nums[i + 1]) - 24) <= eps) ok = 1;
            if (fabs(pre * (nums[i] - nums[i + 1]) - 24) <= eps) ok = 1;
            if (fabs(nums[i] - nums[i + 1]) > eps && fabs(pre / (nums[i] - nums[i + 1]) - 24) <= eps) ok = 1;
            if (fabs(pre > eps) && fabs((nums[i] - nums[i + 1]) / pre - 24) <= eps) ok = 1;
            if (fabs(pre > eps) && fabs((nums[i] + nums[i + 1]) / pre - 24) <= eps) ok = 1;
            if (fabs(pre / (nums[i] + nums[i + 1]) - 24) <= eps) ok = 1;
        }
    };
    do {
        dfs(dfs, 1, nums[0]);
    } while (next_permutation(nums.begin(), nums.end()));
    if (ok) cout << "YES\n";
    else cout << "NO\n";

}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
       solve();
    }
    return 0;
}