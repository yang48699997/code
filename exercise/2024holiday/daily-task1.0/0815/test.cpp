#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

void solve(int n, vector<int> g) {
    string ans;

    vector<pair<int, int>> p;
    vector<set<pair<int, int>>> st(n * n);
    for (int i = 0; i < n * n; i++) {
        int x, y;
        cin >> x >> y;
        if (p.size() == 0) {
            p.emplace_back(x, y);
            ans += '1';
            continue;
        }
        int ok = 1;
        pair<int, int> now = {x, y};
        for (int j = 0; j < p.size(); j++) {
            pair<int, int> res = cal(p[j], now);
            if (st[j].count(res)) {
                ok = 0;
                break;
            }
        }
        if (!ok) {
            ans += '0';
            continue;
        }
        ans += '1';
        for (int j = 0; j < p.size(); j++) {
            pair<int, int> res = cal(p[j], now);
            st[j].insert(res);
        }
        p.push_back(now);
    }
    cout << ans << "\n";
}

void work() {
    int n = 100;
    vector<int> g(n * n);
    for (int i = 0; i < n * n; i++) {
        g[i] = i + 1; 
    }
    for (int i = 0; i < n * n; i++) {
        ll p = rng();
        p %= n * n;
        swap(g[i], g[p]);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}