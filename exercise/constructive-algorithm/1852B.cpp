#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), nums(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        nums[i] = i;
    }
    sort(nums.begin(), nums.end(), [&](int x1, int x2){
        return a[x1] < a[x2];
    });
    sort(a.begin(), a.end());

    vector<int> ans(n);
    int l = 0, r = n - 1;
    int left = n;
    int rm = 0;
    int now = n;
    while (l <= r) {
        if (a[r] < rm || a[r] - rm > left) {
            cout << "NO\n";
            return;
        }
        while (a[r] - rm < left) {
            if (a[l] != rm) {
                cout << "NO\n";
                return;
            }
            ans[nums[l]] = -now;
            left--;
            l++;
            now--;
        }
        if (r < l) break;
        ans[nums[r]] = now;
        r--;
        now--;
        rm++;
        left--;
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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