#include <bits/stdc++.h>
using namespace std;


int T;
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> a(n);
    string ignore;
    for (int i = 0; i < m; i++) ignore += "0";
    for (int i = 0; i < n; i++) {
        if (s[i] == ignore) continue;
        int l = 0;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                l = j;
                break;
            }
        }
        a[i] = m - l - 1;
        for (int j = l + 1; j < m; j++) {
            if (s[i][j] == '1') {
                a[i]++;
                break;
            }
        }
    }

    vector<vector<int>> pre(n + 1, vector<int> (m + 1));
    vector<int> preig(n + 1);
    for (int i = 0; i < n; i++) {
        preig[i + 1] = preig[i];
        for (int j = 0; j <= m; j++) {
            pre[i + 1][j] = pre[i][j];
        }
        if (s[i] == ignore) {
            preig[i + 1]++;
            continue;
        }
        pre[i + 1][a[i]]++;
    };

    vector<int> cnt(m + 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        for (int i = 0; i <= m; i++) {
            cnt[i] = pre[r][i] - pre[l - 1][i];
        }
        int ans = 0;
        int len = r - l + 1 - preig[r] + preig[l - 1];
        if (len == 0) {
            cout << "0\n";
            continue;
        }
        int last = 1;
        for (int i = 0; i <= m ;i++) {
            if (cnt[i] == 0) continue;
            ans = max(ans, i + len - last);
            last = 0;
            len -= cnt[i];
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