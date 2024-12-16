#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    a.push_back(a[0]);
    double ans = 0;
    
    for (int i = 1; i < n; i++) {
        ans += (a[i] + a[i + 1]) * 1.0 / 2;
    }

    cout << fixed << setprecision(2) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}