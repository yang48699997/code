#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll ans = 0;

    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [&](int x1, int x2) {
        return a[x1] < a[x2];
    });
    
    ll res = 0;
    int cnt = 0;
    vector<int> s1, s2;
    for (int i = 0; i < n; i++) {
        if (b[i]) {
            s1.push_back(a[i]);
            continue;
        }
        res = max(res, (ll)a[i]);
        s2.push_back(a[i]);
        cnt++;
    }
    if (cnt) {
        sort(s2.begin(), s2.end());
        sort(s1.begin(), s1.end());
        int l = 0, r = 2e9;
        int pp = (n - 2) / 2;
        s2.pop_back();
        cnt--;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            int ok = 1;
            int lef = k;
            if (pp < cnt && s2[pp] < mid) ok = 0;
            int c = 0;
            for (int i = 0; i < cnt; i++) {
                if (s2[i] >= mid) c++;
            }
            for (int i = s1.size() - 1; i >= 0; i--) {
                if (s1[i] >= mid) {
                    c++;
                } else if (s1[i] + lef >= mid) {
                    c++;
                    lef -= mid - s1[i]; 
                } else break;
            }
            ok &= (c >= (n + 1) / 2);
            if (ok) l = mid + 1;
            else r = mid - 1;
        }
        // cerr << r << "\n";
        res += r;
        ans = max(ans, res);
    }
    
    for (int i = 0; i < n; i++) {
        if (b[nums[i]]) {
            ll res = k + a[nums[i]];
            if (n % 2) {
                if (i < n / 2) res += a[nums[n / 2]];
                else res += a[nums[n / 2 - 1]];
            } else {
                if (i < n / 2) res += a[nums[n / 2]];
                else res += a[nums[n / 2 - 1]];
            }
            ans = max(ans, res);
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