#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());
    vector<int> p = a;
    sort(p.begin(), p.end());
    vector<int> cnt(m + 1);
    int r = n - 1;

    for (int i = m - 1; i >= 0; i--) {
        while (r >= 0 && p[r] >= b[i]) {
            cnt[i] += (p[r] > a[0]);
            r--;
        }
        cnt[i] += cnt[i + 1];
    }


    for (int i = 0; i < m; i++) {
        if (b[i] <= a[0]) cnt[i] = 0;
    }

    cnt.pop_back();
    sort(cnt.begin(), cnt.end());

    vector<ll> ans(m);
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j + i <= m; j += i) {
            ans[i - 1]++;
            ans[i - 1] += cnt[j + i - 1];
        }
    }


    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
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