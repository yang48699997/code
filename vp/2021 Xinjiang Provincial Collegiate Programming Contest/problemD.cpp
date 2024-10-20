#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;

    if (l == r) {
        string ans = string(n, 'a');
        for (int i = 0; i < l; i++) {
            string p;
            for (int j = i; j < n; j += l) {
                p += s[j];
            }
            sort(p.begin(), p.end());
            int now = 0;
            for (int j = i; j < n; j += l) {
                ans[j] = p[now++];
            }
        }
        cout << ans << "\n";
    } else {
        string p;
        for (int i = 0; i < n; i++) {
            if (i + l < n || i >= l) p += s[i];
        }
        sort(p.begin(), p.end());
        string ans;
        int now = 0;
        for (int i = 0; i < n; i++) {
            if (i + l < n || i >= l) ans += p[now++];
            else ans += s[i];
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}