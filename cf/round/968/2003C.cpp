#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26);
    vector<int> nums(26);
    iota(nums.begin(), nums.end(), 0);
    string ans;
    int pre = -1;
    for (char c : s) {
        cnt[c - 'a']++;
    }
    for (int i = 0; i < n; i++) {
        sort(nums.begin(), nums.end(), [&](int x1, int x2) {
            return cnt[x1] > cnt[x2];
        });
        if (nums[0] == pre) {
            if (cnt[nums[1]]) {
                ans += 'a' + nums[1];
                pre = nums[1];
                cnt[nums[1]]--;
            } else {
                ans += 'a' + nums[0];
                cnt[nums[0]]--;
            }
        } else {
            ans += 'a' + nums[0];
            cnt[nums[0]]--;
        }
    }
    cout << ans << "\n";
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