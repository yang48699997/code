#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<int> cnt(3);
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '0') continue;
            cnt[s[i][j] - '1']++;
        }
    }
    cout << (cnt[0] * 2 - cnt[2]) / 3 << " " << cnt[2] - cnt[1] << " " << cnt[0] - 2 * (cnt[0] * 2 - cnt[2]) / 3 - cnt[2] + cnt[1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}