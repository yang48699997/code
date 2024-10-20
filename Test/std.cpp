#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
map<string, double> mp = {
    {"A", 1.0}, {"2", 2.0}, {"3", 3.0}, {"4", 4.0}, {"5", 5.0}, 
    {"6", 6.0}, {"7", 7.0}, {"8", 8.0}, {"9", 9.0}, {"10", 10.0},
    {"J", 11.0}, {"Q", 12.0}, {"K", 13.0},
};

bool dfs(vector<double>& nums, int n) {
    if (n == 1) {
        if (abs(nums[0] - 24.0) <= eps) return true;
        return false;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                vector<double> next_nums;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) next_nums.push_back(nums[k]);
                }
                // 枚举加法
                next_nums.push_back(nums[i] + nums[j]);
                if (dfs(next_nums, n - 1)) return true;
                next_nums.pop_back();
                
                // 枚举乘法
                next_nums.push_back(nums[i] * nums[j]);
                if (dfs(next_nums, n - 1)) return true;
                next_nums.pop_back();
                
                // 枚举减法 (两种顺序)
                next_nums.push_back(nums[i] - nums[j]);
                if (dfs(next_nums, n - 1)) return true;
                next_nums.pop_back();
                next_nums.push_back(nums[j] - nums[i]);
                if (dfs(next_nums, n - 1)) return true;
                next_nums.pop_back();
                
                // 枚举除法 (两种顺序)
                if (abs(nums[j]) > eps) {
                    next_nums.push_back(nums[i] / nums[j]);
                    if (dfs(next_nums, n - 1)) return true;
                    next_nums.pop_back();
                }
                if (abs(nums[i]) > eps) {
                    next_nums.push_back(nums[j] / nums[i]);
                    if (dfs(next_nums, n - 1)) return true;
                    next_nums.pop_back();
                }
            }
        }
    }
    return false;
}

void solve() {
    vector<string> a(4);
    for (int i = 0; i < 4; i++) cin >> a[i];
    
    vector<double> nums(4);
    for (int i = 0; i < 4; i++) nums[i] = mp[a[i]];
    
    if (dfs(nums, 4)) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
