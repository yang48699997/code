#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    auto check = [&](int x, int y) -> int {
        int nx = 0;
        int ny = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                if (y == ny && nx == x + 1) continue;
                else nx--;
            } else if (s[i] == 'R') {
                if (y == ny && nx == x - 1) continue;
                else nx++;
            } else if (s[i] == 'U') {
                if (x == nx && ny == y - 1) continue;
                else ny++;
            } else if (s[i] == 'D') {
                if (x == nx && ny == y + 1) continue;
                else ny--;
            }
        }
        if (nx == 0 && ny == 0) return 1;
        else return 0;
    };

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            x--;
        } else if (s[i] == 'R') {
            x++;
        } else if (s[i] == 'U') {
            y++;
        } else if (s[i] == 'D') {
            y--;
        }

        if (x == 0 && y == 0) continue;

        if (check(x, y)) {
            cout << x << " " << y << "\n";
            return;
        }
    }

    cout << 0 << " " << 0 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}