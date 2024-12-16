#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    int m;
    cin >> n >> m;

    vector<int> r(m), c(m), d1(m), d2(m);
    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i];
        d1[i] = r[i] + c[i];
        d2[i] = r[i] - c[i];
    } 

    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    sort(d1.begin(), d1.end());
    d1.erase(unique(d1.begin(), d1.end()), d1.end());
    sort(d2.begin(), d2.end());
    d2.erase(unique(d2.begin(), d2.end()), d2.end());

    ll ans = (n - c.size()) * (n - r.size());

    for (int i = 0; i < d1.size(); i++) {
        int p = d1[i];
        ans -= n - abs(p - n - 1);
        set<pair<int, int>> st;
        for (int j = 0; j < r.size(); j++) {
            int x = r[j];
            int y = p - x;
            if (x > 0 && x <= n && y > 0 && y <= n) st.insert({x, y});
        }
        for (int j = 0; j < c.size(); j++) {
            int y = c[j];
            int x = p - y;
            if (x > 0 && x <= n && y > 0 && y <= n) st.insert({x, y});
        }
        ans += st.size();
    }

    for (int i = 0; i < d2.size(); i++) {
        int p = d2[i];
        ans -= n - abs(p);
        set<pair<int, int>> st;
        for (int j = 0; j < r.size(); j++) {
            int x = r[j];
            int y = x - p;
            if (x > 0 && x <= n && y > 0 && y <= n) st.insert({x, y});
        }
        for (int j = 0; j < c.size(); j++) {
            int y = c[j];
            int x = p + y;
            if (x > 0 && x <= n && y > 0 && y <= n) st.insert({x, y});
        }
        for (int j = 0; j < d1.size(); j++) {
            if (abs(p + d1[j]) & 1) continue;
            int x = (p + d1[j]) / 2;
            int y = d1[j] - x;
            if (x > 0 && x <= n && y > 0 && y <= n) st.insert({x, y});
        }
        ans += st.size();
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}