#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int cnt = 100;
    int x = 0, y = 0;
    while (cnt--) {
        if (x == a && y == b) {
            cout << "YES\n";
            return;
        }
        for (char c : s) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'W') x--;
            else x++;
            if (x == a && y == b) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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