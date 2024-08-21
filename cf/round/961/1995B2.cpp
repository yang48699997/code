#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> c(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<int> nums(n);
    for (int i = 0; i < n; i++) nums[i] = i;
    sort(nums.begin(), nums.end(), [&] (int x, int y){
        return a[x] < a[y];
    }); 
    for (int i = 0; i < n; i++) {
        ans = max(ans, min(m / a[i], c[i]) * a[i]);
        if (i == 0) continue;
        if (a[nums[i]] - a[nums[i - 1]] > 1) continue;
        ll p = m / a[nums[i - 1]];
        ll c1 = c[nums[i - 1]];
        ll c2 = c[nums[i]];
        ll res = min(p, c1) * a[nums[i - 1]];
        ll dif = m - res;
        res += min(c2, dif / a[nums[i]]) * a[nums[i]];
        ll q = m - res;
        res += min({q, c1, p, c2 - min(c2, dif / a[nums[i]])});
        ans = max(ans, res);
    }
    cout << ans << "\n";
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