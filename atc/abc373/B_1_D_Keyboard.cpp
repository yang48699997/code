#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    vector<int> p(26);
    cin >> s;
    for (int i = 0; i < 26; i++) {
        p[s[i] - 'A'] = i;
    }
    int ans = 0;
    for (int i = 1; i < 26; i++) {
        ans += abs(p[i] - p[i - 1]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}