#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (b[i - 1] == 'x' && b[i + 1] == 'x' && a[i] == '.' && b[i] == '.' && a[i + 1] == '.' && a[i - 1] == '.') ans++;
        if (a[i - 1] == 'x' && a[i + 1] == 'x' && b[i] == '.' && a[i] == '.' && b[i + 1] == '.' && b[i - 1] == '.') ans++;
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