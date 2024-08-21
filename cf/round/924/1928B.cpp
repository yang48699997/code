#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int m = unique(a.begin(), a.end()) - a.begin();
    a.resize(m);
    int ans = 0;
    int l = m - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (l >=0 && a[i] - a[l] < n) l--;
        ans = max(ans, i - l);
    }
    cout << ans << "\n";
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