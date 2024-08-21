#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int gcd(int x, int y) {
    if (x == 0) return y;
    if (y == 0) return x;
    while (y) {     
        int t = y;
        y = x % y;
        x = t;
    };
    return x;
}

pair<int, int> cal(pair<int, int> p1, pair<int, int> p2) {
    int x = p2.first - p1.first;
    int y = p2.second - p1.second;
    int g = gcd(abs(x), abs(y));
    x /= g;
    y /= g;
    if (x < 0) {
        x *= -1;
        y *= -1;
    } else if (x == 0 && y < 0) {
        y *= -1;
    }
    return {x, y};
}

void solve() {
    int n;
    cin >> n;
    string ans;
    
    vector<pair<int, int>> p;
    vector<vector<int>> v(n + 1,vector<int> (n + 1, 1));
    for (int i = 0; i < n * n; i++) {
        int x, y;
        cin >> x >> y;
        if (!v[x][y]) {
            ans += '0';
            continue;
        }
        ans += '1';
        pair<int, int> now = {x, y};
        for (int j = 0; j < p.size(); j++) {
            pair<int, int> res = cal(p[j], now);
            x = p[j].first;
            y = p[j].second;
            while (x > 0 && x <= n && y > 0 && y <= n) {
                v[x][y] = 0;
                x += res.first;
                y += res.second;
            }
            x = p[j].first;
            y = p[j].second;
            while (x > 0 && x <= n && y > 0 && y <= n) {
                v[x][y] = 0;
                x -= res.first;
                y -= res.second;
            }
        }
        p.push_back(now);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}