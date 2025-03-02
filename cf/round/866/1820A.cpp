#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    int ans = 0;
    int cnt = 0;

    if (s[0] == '_') ans++;
    if (s.back() == '_') ans++;
    if (s == "^") ans++;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '^') continue;
        int j = i;
        while (j < s.size() && s[j] != '^') j++;
        ans += j - i - 1;
        i = j - 1;
    }

    if (cnt) ans++;

    cout << ans << '\n';
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