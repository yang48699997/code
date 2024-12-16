#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    map<int, int> cnt;
    for (int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for (auto [_, c] : cnt) ans += c / 2;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}