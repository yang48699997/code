#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int ok = 1;
    int p5 = 0;
    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '3') {
            cnt++;
            cnt2++;
            if (cnt >= 90) ok = 0;
            if (cnt2 >= 10) ok = 0;
        } else if (s[i] == '4') {
            cnt++;
            if (cnt >= 90) ok = 0;
            cnt2 = 0;
        } else if (s[i] == '5') {
            if (p5) ok = 0;
            cnt = 0;
            cnt2 = 0;
            p5 = 1;
        } else {
            cnt = 0;
            cnt2 = 0;
            p5 = 0;
        }
    }
    if (ok) cout << "valid\n";
    else cout << "invalid\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}