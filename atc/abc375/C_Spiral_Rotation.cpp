#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    auto work = [&](int p) -> void {
        for (int i = p; i < n - p - 1; i++) {
            vector<char> now = {g[p][i], g[i][n - p - 1], g[n - p - 1][n - i - 1], g[n - i - 1][p]};
            g[p][i] = now[3];
            g[i][n - p - 1] = now[0];
            g[n - p - 1][n - i - 1] = now[1];
            g[n - i - 1][p] = now[2];
        }
    };

    for (int i = 0; i < n / 2; i++) {
        int p = (i + 1) % 4;
        while (p--) {
            work(i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}