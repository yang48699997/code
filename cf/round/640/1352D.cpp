#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans1 = 0, ans2 = 0;
    int l = 0, r = n - 1;
    int p1 = 0, p2 = 0;
    int cnt1 = 0, cnt2 = 0;
    while (l <= r) {
        ans1++;
        p1 = 0;
        while (l <= r && p1 <= p2) {
            p1 += a[l++];
        }
        cnt1 += p1;
        if (l > r) break;
        p2 = 0;
        ans2++;
        while (l <= r && p2 <= p1) {
            p2 += a[r--];
        }
        cnt2 += p2;
    }

    cout << ans1 + ans2 << " " << cnt1 << " " << cnt2 << "\n";
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