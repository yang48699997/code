#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << max(0, t - a[n - p]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}