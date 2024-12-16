#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'p') s[i] = 'q';
        else if (s[i] == 'q') s[i] = 'p';
    }

    cout << s << "\n";
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