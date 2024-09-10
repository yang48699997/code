#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> pre0(26), suf0(26);
    vector<int> pre1(26), suf1(26);
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (i & 1) suf0[s[i] - 'a']++;
        else suf1[s[i] - 'a']++;
    }
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            suf0[s[i] - 'a']--;
        } else {
            suf1[s[i] - 'a']--;
        }
        int res = n;
        int mx1 = 0;
        int mx2 = 0;
        for (int j = 0; j < 26; j++) {
            mx1 = max(mx1, pre0[j] + suf0[j]);
            mx2 = max(mx2, pre1[j] + suf1[j]);
        }
        if (n & 1)
        ans = min(ans, res - mx1 - mx2);
        if (i & 1) {
            pre1[s[i] - 'a']++;
        } else {
            pre0[s[i] - 'a']++;
        }
    }
    int mx1 = 0;
    int mx2 = 0;
    for (int i = 0; i < 26; i++) {
        mx1 = max(mx1, pre0[i]);
        mx2 = max(mx2, pre1[i]);
    }
    if (n & 1 ^ 1)
    ans = min(ans, n - mx1 - mx2);
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