#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0;
    map<int, int> cnt;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] - i]++;
        mp[a[i] - i].push_back(a[i]);
        ans += a[i];
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        int p = it -> first;
        auto &b = it -> second;
        sort(b.rbegin(), b.rend());
        if (cnt[p] & 1) {
            ans -= b.back();
            b.pop_back();
        }
        while (!b.empty()) {
            int now = b.back();
            b.pop_back();
            now += b.back();
            b.pop_back();
            if (now < 0) {
                ans -= now;
            } else break;
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