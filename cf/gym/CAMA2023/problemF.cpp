#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mx = 2e5 + 5;

void solve() {
    int q;
    cin >> q;
    vector<int> v(mx);
    vector<set<int>> p(mx);
    int ans = 0;
    vector<vector<int>> have(q);
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            int k;
            cin >> k;
            while (k--) {
                int x;
                cin >> x;
                have[i].push_back(x);
                if (p[x].empty()) {
                    v[i]++;
                    if (v[i] == 1) ans++;
                }
                p[x].insert(i);
            }
        } else if (c == 2) {
            int k;
            cin >> k;
            k--;
            for (int x : have[k]) {
                if (*p[x].begin() == k) {
                    v[k]--;
                    if (v[k] == 0) ans--;
                    p[x].erase(k);
                    if (!p[x].empty()) {
                        v[*p[x].begin()]++;
                        if (v[*p[x].begin()] == 1) ans++;
                    }
                } else p[x].erase(k);
            }
        } else {
            cout << ans << "\n";
        }
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