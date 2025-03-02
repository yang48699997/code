#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<ll, 2>> p(n);
    ll h = 0, w = 0;
    ll S = 0;

    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
        h = max(h, p[i][0]);
        w = max(w, p[i][1]);
        S += p[i][0] * p[i][1];
    }

    vector<array<ll, 2>> ans;

    auto check = [&](ll x, ll y) -> void {
        if (x * y != S) return;

        ans.push_back({x, y});
        vector<int> v(n);
        priority_queue<array<ll, 3>> q1, q2;

        for (int i = 0; i < n; i++) {
            q1.push({p[i][0], p[i][1], i});
            q2.push({p[i][1], p[i][0], i});
        }

        int t = n;
        while (t--) {
            while (!q1.empty() && v[q1.top()[2]]) q1.pop();
            while (!q2.empty() && v[q2.top()[2]]) q2.pop();
            if (q1.top()[0] == x) {
                y -= q1.top()[1];
                v[q1.top()[2]] = 1;
            } else if (q2.top()[0] == y) {
                x -= q2.top()[1];
                v[q2.top()[2]] = 1;
            } else {
                break;
            }
        }

        if (accumulate(v.begin(), v.end(), 0) != n) {
            ans.pop_back();
        }

    };

    check(h, S / h);
    check(S / w, w);

    if (ans.size() == 2 && ans[0] == ans[1]) ans.pop_back();

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
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