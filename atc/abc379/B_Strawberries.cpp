#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') continue;
        int j = i;
        while (j < n && s[j] == 'O') j++;
        ans += (j - i) / k;
        i = j - 1;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}