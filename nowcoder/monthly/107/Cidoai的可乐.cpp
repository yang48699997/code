#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<int> d(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [&](int x, int y) {
        return a[x] < a[y];
    });

    ll ans = 0;

    priority_queue<array<int, 2>> q;
    q.push({-a[nums[0]], d[nums[0]]});
    
    for (int i = 1; i < n; i++) {
        while (!q.empty() && q.top()[1] == 0) q.pop();
        auto [val, t] = q.top();
        q.pop();

        ans -= val;
        t--;
        q.push({val, t});
        q.push({-a[nums[i]], d[nums[i]]});
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}