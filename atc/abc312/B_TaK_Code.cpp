#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];


    auto check = [&](int x, int y) -> bool {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                char c = '.';
                if (i == 3 || j == 3) c = '#';
                if (s[x + i][y + j] == c || s[x + 8 - i][y + 8 - j] == c) return false;
            }
        }

        return true;
    };

    for (int i = 0; i < n - 8; i++) {
        for (int j = 0; j < m - 8; j++) {
            if (check(i, j)) cout << i + 1 << " " << j + 1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}