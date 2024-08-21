#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    map<pair<int,int>, deque<int>> cnt;
    int cx = 0, cy = 0;
    ll ans = 0;
    cnt[{0,0}].push_back(-1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            cx--;
        } else if (s[i] == 'W') {
            cy++;
        } else if (s[i] == 'S') {
            cy--;
        } else if (s[i] == 'D') {
            cx++;
        }
        cnt[{cx,cy}].push_back(i);
    }
    if (cnt.count({x, y})) {
        int p = cnt[{x, y}].front();
        if (p == -1) ans += n;
        else ans += n - p;
    }
    cx = cy = 0;
    // cnt[{0, 0}].pop_front();
    // if (cnt[{0, 0}].size() == 0) cnt.erase({0, 0});
    for (int i = 0; i < n; i++) {
        cnt[{cx,cy}].pop_front();
        if (cnt[{cx, cy}].size() == 0) cnt.erase({cx, cy});
        if (s[i] == 'A') {
            cx--;
        } else if (s[i] == 'W') {
            cy++;
        } else if (s[i] == 'S') {
            cy--;
        } else if (s[i] == 'D') {
            cx++;
        }
        if (cnt.count({x + cx, y + cy})) {
            int p = cnt[{x + cx, y + cy}].front();
            if (p == i) ans += n - i - 1;
            else ans += n - p;
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