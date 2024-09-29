#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    const int block = sqrt(n);
    vector<pair<int, int>> ask(q);
    vector<int> nums(q);
    iota(nums.begin(), nums.end(), 0);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        ask[i] = make_pair(l, r);
    }
    sort(nums.begin(), nums.end(), [&](int x1, int x2){
        if (ask[x1].first / block != ask[x2].first / block) return ask[x1].first / block < ask[x2].first / block;
        else return ask[x1].second < ask[x2].second;
    });
    vector<int> b = a;
    sort(b.begin(), b.end());
    int m = unique(b.begin(), b.end()) - b.begin();
    b.resize(m);
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    int l = 0, r = -1;
    vector<int> ans(q);
    vector<int> cnt(m);
    int p = 0;
    for (int i : nums) {
        int cl = ask[i].first;
        int cr = ask[i].second;
        if ((cr - cl + 1) & 1) continue;
        while (l < cl) {
            if (cnt[a[l]] & 1) p--;
            cnt[a[l]]--;
            if (cnt[a[l]] & 1) p++;
            l++;
        }
        while (l > cl) {
            l--;
            if (cnt[a[l]] & 1) p--;
            cnt[a[l]]++;
            if (cnt[a[l]] & 1) p++;
        }
        while (r < cr) {
            r++;
            if (cnt[a[r]] & 1) p--;
            cnt[a[r]]++;
            if (cnt[a[r]] & 1) p++;
        }
        while (r > cr) {
            if (cnt[a[r]] & 1) p--;
            cnt[a[r]]--;
            if (cnt[a[r]] & 1) p++;
            r--;
        }
        ans[i] = !p;
    }
    for (int i = 0; i < q; i++) {
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
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