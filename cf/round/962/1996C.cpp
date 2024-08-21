#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> cnt(n + 1, vector<int> (26));
    for (int i = 0; i < n; i++) {
        int x = a[i] - 'a';
        int y = b[i] - 'a';
        for (int j = 0; j < 26; j++) {
            cnt[i + 1][j] = cnt[i][j];
            if (x == j) cnt[i + 1][j]++;
            if (y == j) cnt[i + 1][j]--;
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int c = 0;
        for (int j = 0; j < 26; j++) {
            c += abs(cnt[r][j] - cnt[l - 1][j]);
        }
        c /= 2;
        cout << c << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}