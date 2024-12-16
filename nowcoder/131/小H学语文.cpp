#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    
    sort(nums.begin(), nums.end(), [&](int x, int y) {
        return a[x] > a[y];
    });

    ll res = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        ll now = i * i;
        now *= a[nums[i]];
        if (now >= res) cnt = i + 1;
        res = max(res, now);
    }

    vector<int> ans(cnt);
    for (int i = 0; i < cnt; i++) {
        ans[i] = nums[i] + 1;
    }

    sort(ans.begin(), ans.end());
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        cout << ans[i] << " \n"[i == cnt - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}