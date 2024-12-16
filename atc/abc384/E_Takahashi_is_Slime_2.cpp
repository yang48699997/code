#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dir[4][2] = {
    {1, 0},
    {0, 1},
    {0, -1},
    {-1, 0}
};

void solve() {
    int n, m;
    ll x;
    int p, q;
    cin >> n >> m >> x >> p >> q;
    p--;
    q--;

    vector<vector<ll>> g(n, vector<ll> (m));
    vector<vector<int>> v(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    ll X = g[p][q];
    v[p][q] = 1;
    priority_queue<array<ll, 3>> pq;


    auto check = [&](int a, int b) -> bool {
        if (a >= 0 && a < n && b >= 0 && b < m && !v[a][b]) return true;
        return false;
    };

    for (int i = 0; i < 4; i++) {
        int nx = p + dir[i][0];
        int ny = q + dir[i][1];
        if (check(nx, ny)) {
            pq.push({-g[nx][ny], nx, ny});
        }
    }
    
    while (!pq.empty()) {
        auto [val, a, b] = pq.top();
        pq.pop();
        if (v[a][b]) continue;
        ll now = -val;
        if (X / x < now) break;
        else if (X / x == now && X % x == 0) break;
        else {
            v[a][b] = 1;
            X -= val;

            for (int i = 0; i < 4; i++) {
                int nx = a + dir[i][0];
                int ny = b + dir[i][1];

                if (check(nx, ny)) pq.push({-g[nx][ny], nx, ny});
            }
        }
    }

    cout << X << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}