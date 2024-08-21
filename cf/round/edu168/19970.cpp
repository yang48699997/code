#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    string s;
    cin >> s;
    if (s.length() == 1) {
        if (s == "a") cout << "ab\n";
        else cout << (s + "a") << "\n";
    } else {
        string ans;
        int ok = 1;
        for (int j = 0; j < s.length() - 1; j++) {
            ans += s[j];
            if (s[j] == s[j + 1] && ok) {
                for (int i = 0; i < 26; i++) {
                    char c = 'a' + i;
                    if (c != s[j] && c != s[j + 1]) {
                        ans += c;
                        break;
                    }
                }
                ok = 0;
            }
        }
        ans += s.back();
        if (ok) {
            if (s.back() == 'a') ans += 'b';
            else ans += 'a';
        }
        cout << ans << "\n";
    }
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