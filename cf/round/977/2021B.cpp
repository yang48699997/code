#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    map<int, vector<int>> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] % x].push_back(a[i]);
    }

    vector<int> v(n);
    int ans = n;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        auto &p = it -> second;
        sort(p.begin(), p.end());
        int now = it -> first;
        for (int i : p) {
            if (now >= n) break;
            if (i <= now) {
                v[now] = 1;
                now += x;
            } else break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            ans = i;
            break;
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