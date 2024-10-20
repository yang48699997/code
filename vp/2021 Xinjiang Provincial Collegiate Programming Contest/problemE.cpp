#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    vector<ll> a;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        a.push_back(p[i].first);
        a.push_back(p[i].second);
    }
    map<int, ll> mp;

    ll ans = 0;
    for (auto [x, y] : p) {
        ll cnt = 0;
        if (y >= x) {
            ans += y - x;
            cnt++;
            auto it = mp.begin();
            while (it != mp.end() && it -> first < y) {
                ans += it -> second * (y - it -> first);
                cnt += it -> second;
                it = mp.erase(it);
            }
            mp[y] += cnt;
        } else {
            auto it = mp.begin();
            while (it != mp.end() && it -> first < x) {
                ans += it -> second * (x - it -> first);
                cnt += it -> second;
                it = mp.erase(it);
            }
            mp[x] += cnt;
            mp[y]++;
        }
    }

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}