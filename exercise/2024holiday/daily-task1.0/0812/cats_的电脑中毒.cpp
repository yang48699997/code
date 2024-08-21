#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    sort(s.begin(), s.end());
    int ans = n;
    do {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[0][i] == '1') {
                if (s[1][i] == '0') cnt1++;
                if (s[2][i] == '0') cnt2++;
            } else {
                if (s[1][i] == '1') cnt1++;
                if (s[2][i] == '1') cnt2++;
            }
        }
        int cnt = max(cnt1, cnt2);
        int res = n - cnt;
        int l = res, r = n;
        while (l + 1 < r) {
            res++;
            l++;
            r--;
        }
        ans = min(ans, res);
    } while (next_permutation(s.begin(), s.end()));
    
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