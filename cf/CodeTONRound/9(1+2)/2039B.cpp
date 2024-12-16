#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    if (n == 1) {
        cout << "-1\n";
    } else if (n == 2) {
        if (s[0] == s[1]) {
            cout << s << "\n";
        } else cout << "-1\n";
        return;
    } else {
        for (int i = 0; i < n - 2; i++) {
            string p = s.substr(i, 3);
            if (p[0] == p[1]) {
                cout << p[0] << p[1] << "\n";
                return;
            } else if (p[1] == p[2]) {
                cout << p[1] << p[2] << "\n";
                return;
            } else if (p[0] != p[1] && p[0] != p[2] && p[1] != p[2]) {
                cout << p[0] << p[1] << p[2] << "\n";
                return;
            }
        }
        cout << "-1\n";
    }
}
/* 
aaa
aba
aab
abb
abc

ababa
 */

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