#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int k, n;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [&](int x1, int x2) {
        return a[x1] < a[x2];
    });

    ll ans = 1e18;
    priority_queue<int> q;
    ll sum = 0;
    for (int i = 0; i < k - 1; i++) {
        q.push(b[nums[i]]);
        sum += b[nums[i]];
    }

    for (int i = k - 1; i < n; i++) {
        ans = min(ans, (sum + b[nums[i]]) * a[nums[i]]);
        if (!q.empty() && b[nums[i]] < q.top()) {
            sum -= q.top();
            q.pop();
            sum += b[nums[i]];
            q.push(b[nums[i]]);
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