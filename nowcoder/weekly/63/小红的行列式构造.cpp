#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
    int x;
    cin >> x;
    vector<vector<int>> g(3, vector<int> (3, 1));

    if (x != -1) {
        g[0][0] = x + 1;
        g[1][1] = 2;
    } else {
        g = {
            {2, 1, 1},
            {3, 2, 1},
            {1, 1, -1}
        };
    }
    

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << g[i][j] << " \n"[j == 2];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}