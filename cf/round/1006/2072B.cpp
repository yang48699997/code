#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<ll> cnt(2);
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') cnt[0]++;
        else cnt[1]++;
    }

    cout << cnt[0] / 2 * cnt[1] * (cnt[0] - cnt[0] / 2) << "\n";
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