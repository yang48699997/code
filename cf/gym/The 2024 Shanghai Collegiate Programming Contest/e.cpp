#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string tar = "shanghai";
    vector<int> cnt(8);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i] == tar[j] || s[i] == (tar[j] ^ 32)) cnt[j]++;
        }
    }
    int ans = 1e9;
    cnt[1] /= 2;
    cnt[2] /= 2;
    for (int i = 0; i < 8; i++) ans = min(ans, cnt[i]);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}