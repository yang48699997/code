#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    const int inf = 1e9;

    int key = 0;
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
        key = 1;
    }

    vector<pair<int, int>> ans;
    if (x3 <= x1) {
        ans.push_back({inf, y1});
        ans.push_back({inf, y2});
    } else {
        ans.push_back({-inf, y1});
        if (y2 >= y3) {
            ans.push_back({-inf, inf});
            ans.push_back({x2, inf});
        } else {
            ans.push_back({-inf, -inf});
            ans.push_back({x2, -inf});
        }
    }


    if (key) reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}