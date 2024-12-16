#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    vector<vector<array<int, 2>>> e(n);
    vector<vector<int>> p(2);
    for (int i = 0; i < n; i++) {
        p[s[i] - '0'].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        auto it1 = upper_bound(p[s[i] - '0'].begin(), p[s[i] - '0'].end(), i);
        auto it2 = upper_bound(p[1 - s[i] + '0'].begin(), p[1 - s[i] + '0'].end(), i);
        if (it1 != p[s[i] - '0'].end()) {
            e[i].push_back({*it1, x});
        }
        if (it2 != p[1 - s[i] + '0'].end()) {
            e[i].push_back({*it2, y});
        }
    }

    priority_queue<array<ll, 2>> q;
    q.push({0, 0});
    vector<int> v(n);
    vector<ll> d(n, 1e18); 
    d[0] = 0;

    while (!q.empty()) {
        auto [dis, x] = q.top();
        dis = -dis;
        q.pop();

        if (v[x]) continue;
        v[x] = 1;

        for (auto [nxt, w] : e[x]) {
            if (dis + w < d[nxt]) {
                q.push({-dis - w, nxt});
                d[nxt] = dis + w;
            }
        }
    }

    cout << d[n - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}