#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    ll ans = 0;
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n && s[j] != s[j - 1]) j++;
        ans += 1LL * (j - i) * (j - i - 1) / 2;
        i = j;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}