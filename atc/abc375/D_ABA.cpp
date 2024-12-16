#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    ll ans = 0;
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'A'].push_back(i);
    }

    for (int i = 0; i < 26; i++) {
        ll sum = 0;
        ll cnt = 0;
        for (int j : pos[i]) {
            ans += cnt * (j - 1) - sum;
            sum += j;
            cnt++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}