#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int p = 0;
    string ans;
    if (s[0] == '0') {
        cout << s << "\n";
        return;
    }
    for (int i = 31; i >= 0; i--) {
        if (i == 0) {
            if (p) ans += '1';
            else ans += '0';

        } else if (p) {
            if (s[i] == '0') ans += '1';
            else ans += '0';
        } else {
            if (s[i] == '0') ans += '0';
            else {
                ans += '1';
                p = 1;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}