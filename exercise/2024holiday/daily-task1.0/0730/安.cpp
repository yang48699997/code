#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 0;
    int e = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) ans++;
        else if (a[i] == b[i]) e++;
    }
    ans += (e + 1) / 2;
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