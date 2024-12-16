#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
    }

    ll ans = 0;
    vector<array<int, 2>> p;
    p.push_back({0, 0});

    for (int i = 0; i < n; i++) {
        vector<array<int, 2>> tmp;
        for (int j = p.size() - 1; j >= 0; j--) {
            int now = (a[i] | p[j][0]);
            if (tmp.empty() || tmp.back()[0] != now) {
                tmp.push_back({now, p[j][1]});
            }
        }
        reverse(tmp.begin(), tmp.end());
        swap(p, tmp);
        for (int j = p.size() - 1; j >= 0; j--) {
            int now = p[j][0], pos = p[j][1];
            int pre = -1;
            if (j != 0) pre = p[j - 1][1];
            int d = pos - pre;
            ans += d;
            auto &e = mp[now];
            if (e.empty()) continue;
            auto it = upper_bound(e.begin(), e.end(), pos);
            it--;
            int pp = *it;
            if (pp > pre && pp <= pos) ans -= pp - pre;
        }
        p.push_back({0, i + 1});
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}