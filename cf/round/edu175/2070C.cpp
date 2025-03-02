#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'R' && p.empty()) continue;

        int j = i;
        int mx = a[j];
        while (j < n && s[j] == s[i]) {
            mx = max(mx, a[j]);
            j++;
        }
        if (j != n || s[i] != 'R') p.push_back(mx);
        i = j - 1;
    }

    int l = 0, r = 1e9;

    auto check = [&](int x) -> bool {
        int cnt = 0;
        int ok = 0;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] <= x) continue;
            if (i & 1) ok = 0;
            else {
                if (!ok) cnt++;
                ok = 1;
            }
        }
        return cnt <= k;
    };

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }

    cout << l << "\n";
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