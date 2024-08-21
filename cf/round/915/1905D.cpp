#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;

    deque<pair<int, int>> p;
    int l = 0;
    for (int i = 0; i < n; i++) {
        v[a[i]] = 1;
        while (l < n && v[l]) l++;
        ans += l;
        if (p.size() == 0 || p.back().first != l) p.emplace_back(l, i);
    }
    ll res = ans;
    for (int i = 0; i < n - 1; i++) {
        while (p.front().second < i) {
            ll x = p.front().second;
            int y = p.front().first;
            p.pop_front();
            if (p.front().second >= i) {
                res -= (i - x) * y;
                if (p.front().second > i) p.push_front({y, i});
            } else {
                res -= (p.front().second - x) * y;
            }
        }
        int x = a[i];
        ll r = n + i;
        while (!p.empty() && p.back().first > x) {
            res -= (r - p.back().second) * p.back().first;
            r = p.back().second;
            p.pop_back();
        }
        res += (n + i - r) * x;
        p.emplace_back(x, r);
        p.emplace_back(n, n + i);
        res += n;
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}