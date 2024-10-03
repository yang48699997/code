#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x, y;
    char c;
    string s = "signed ";
    string us = "unsigned ";
    cin >> x >> c >> y;
    if (y >= 0) {
        if (x < 0) {
            cout << us << (y - x - 1) << "\n"; 
        } else if (x < y) {
            cout << "-1\n";
        } else if (x == y) {
            cout << us << x << "\n";
        } else {
            int d = x - y - 1;
            if (d < y) cout << "-1\n";
            else cout << us << d << "\n";
        }
    } else {
        if (x <= 0) {
            if (x > y) cout << "-1\n";
            else if (x == y) {
                cout << s << -x - 1 << "\n";
            } else {
                int d = y - x;
                if (d / 2 < -y || (d & 1)) cout << "-1\n";
                else cout << s << d / 2 - 1 << "\n";
            }
        } else {
            if (x < abs(y)) cout << "-1\n";
            else if ((x - abs(y)) & 1) cout << "-1\n";
            else cout << s << -y - 1 + (x + y) / 2 << "\n";
        }
    }
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