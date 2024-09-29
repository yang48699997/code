#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    string t = "narek";
    for (int i = 0; i < 1 << 5; i++) {
        string p;
        for (int j = 0; j < 5; j++) {
            if (1 << j & i) p += s[j];
        }
        int res = 0;
        int l = 0;
        for (int j = 0; j < p.size(); j++) {
            if (p[j] == t[l]) {
                res++;
                l++;
                l %= 5;
            } else if (p[j] == t[0] || p[j] == t[1] || p[j] == t[2] || p[j] == t[3] || p[j] == t[4]) {
                res--;
            }
        }
        res -= l;
        ans = max(ans, res);
    }
    cout << ans << "\n";
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