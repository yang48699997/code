#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;

    vector<array<int, 2>> hurdle(n);
    for (int i = 0; i < n; i++) {
        cin >> hurdle[i][0] >> hurdle[i][1];
    }
    vector<array<int, 2>> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    ll k = 1;
    ll now = 1;
    int l1 = 0, l2 = 0;
    priority_queue<int> q;

    int ans = 0;
    while (l1 < n && now < L) {
        int l = hurdle[l1][0];
        int r = hurdle[l1][1];
        l1++;
        while (l2 < m && p[l2][0] < l) {
            q.push(p[l2++][1]);
        }

        while (k < r - l + 2 && !q.empty()) {
            ans++;
            k += q.top();
            q.pop();
        }

        if (k < r - l + 2) {
            cout << "-1\n";
            return;
        }

        while (l2 < m && p[l2][0] <= r) {
            l2++;
        }
        now = r + 1;
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