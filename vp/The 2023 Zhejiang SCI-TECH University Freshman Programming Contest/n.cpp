#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(8);
    vector<int> l(8);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        cnt[x]++;
    }
    for (int i = 0; i < 8; i++) {
        cin >> l[i];
    }
    int ans = 0;
    for (int i = 0; i < 8; i++) ans += min(l[i], cnt[i]);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}