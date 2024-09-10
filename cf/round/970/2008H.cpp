#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> ans(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    int t = n / 2 + 1;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int sum = 0;
            for (int j = 0; j <= n; j += i) {
                sum += cnt[min(n, j + mid)] - cnt[max(0, j - 1)];
            }
            if (sum >= t) r = mid - 1;
            else l = mid + 1;
        }
        ans[i] = l;
    }
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << " \n"[q == 0];
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