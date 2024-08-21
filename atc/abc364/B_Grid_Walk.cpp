#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    string p;
    cin >> p;

    for (char c : p) {
        if (c == 'R') {
            if (y + 1 < w && s[x][y + 1] == '.') y++;
        } else if (c == 'L') {
            if (y > 0 && s[x][y - 1] == '.') y--;
        } else if (c == 'D') {
            if (x + 1 < h && s[x + 1][y] == '.') x++;
        } else {
            if (x > 0 && s[x - 1][y] == '.') x--;
        }
    }

    cout << x + 1 << " " << y + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}