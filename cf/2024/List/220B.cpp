#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> cnt(n + 1);

    vector<pair<int, int>> ask(q);
    for (int i = 0; i < q; i++) {
        cin >> ask[i].first >> ask[i].second;
        ask[i].first--;
        ask[i].second--;
    }
    vector<int> nums(q), ans(q);
    iota(nums.begin(), nums.end(), 0);
    const int block = sqrt(n);
    sort(nums.begin(), nums.end(), [&](int x1, int x2) {
        if (ask[x1].first / block != ask[x2].first / block) return ask[x1].first / block < ask[x2].first / block;
        return ask[x1].second < ask[x2].second;
    });

    int l = 0, r = -1;
    int res = 0;
    for (int i = 0; i < q; i++) {
        while (l < ask[nums[i]].first) {
            if (a[l] <= n) {
                if (cnt[a[l]] == a[l]) res--;
                cnt[a[l]]--;
                if (cnt[a[l]] == a[l]) res++;
            }
            l++;
        }
        while (l > ask[nums[i]].first) {
            l--;
            if (a[l] > n) continue;
            if (cnt[a[l]] == a[l]) res--;
            cnt[a[l]]++;
            if (cnt[a[l]] == a[l]) res++;
        }
        while (r > ask[nums[i]].second) {
            if (a[r] <= n) {
                if (cnt[a[r]] == a[r]) res--;
                cnt[a[r]]--;
            }
            if (a[r] <= n && cnt[a[r]] == a[r]) res++;
            r--;
        }
        while (r < ask[nums[i]].second) {
            r++;
            if (a[r] > n) continue;
            if (cnt[a[r]] == a[r]) res--;
            cnt[a[r]]++;
            if (cnt[a[r]] == a[r]) res++;
        }
        ans[nums[i]] = res;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}