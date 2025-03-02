#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 1LL * n * (n + 1) / 2;

    for (int k = 1; k <= 10; k++) {
        map<int, int> cnt, cnt2; 
        int x = 0;
        
        for (int i = 0; i < n; i++) {
            int res = a[i] <= k ? -1 : 1;
            int ok = a[i] == k;

            if (ok) {
                cnt[-x]++;
                for (auto it : cnt2) {
                    cnt[it.first] += it.second;
                }
                cnt2.clear();
            } else {
                cnt2[-x]++;
            }

            x += res;

            ans -= cnt[-x];
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