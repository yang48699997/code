#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            a[i].emplace_back(x);
        }
        sort(a[i].begin(), a[i].end());
    }
    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        vector<int> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
            p[i]--;
        }
        int pp;
        cin >> pp;
        int l = 1, r = 1e9;

        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            for (int i : p) {
                cnt += upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();                
            }
            if (cnt >= pp) r = mid - 1;
            else l = mid + 1;
        }

        cout << l << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}