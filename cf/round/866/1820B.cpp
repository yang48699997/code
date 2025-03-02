#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    ll ans = 0;
    s += s;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        int j = i;
        int cnt = 0;
        while (j < n * 2 && s[j] == '1') {
            cnt++;
            j++;
        }
        i = j;
        ans = max(ans, (ll)cnt);
    }

    if (ans == n * 2) ans = ans * n / 2;
    else {
        int p = (ans + 1) / 2;
        ans = p * (ans + 1 - p);
    }

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