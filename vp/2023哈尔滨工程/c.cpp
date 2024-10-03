#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mx = 3e5 + 5;
void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p.emplace_back(x, y);
    }
    sort(p.begin(), b.end());

    set<pair<int, int>> st1, st2;
    vector<set<int>> px(mx + 1);
    vector<set<int>> py(mx + 1);
    st1.emplace(p[0].first);
    st2.emplace(p[0].second);
    for (int i = 1; i < n; i++) {
        int cx = p[i].first;
        int cy = p[i].second;
        auto it = st1.upper_bound(cx);
        if (it != st1.begin()) {
            it--;
            auto it2 = st2.upper_bound(cy);
            if (it2 != st2.begin()) {
                it2--;
                int X = *it;
                int Y = *it2;
                auto pp = upper_bound(px[X].begin(), px[X].end(), X);
                if (pp != px[X].begin() && *(--pp) == Y) ans++;
                else ans += 2;
            } else {
                auto pp = upper_bound(px[X].begin(), px[X].end(), X);
                if (pp != px[X].begin()) ans++;
            }
        } else {

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