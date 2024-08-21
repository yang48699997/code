#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int gcd(int x, int y) {
    if (x == -1) return y;
    while (y) {
        int t = y;
        y = x % y;
        x = t;
    };
    return x;
};
void solve() {
    int n;
    cin >> n;
    int g = -1;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n / 2; i++) {
        if (a[i] == a[n - i - 1]) continue;
        g = gcd(g, abs(a[i] - a[n - i - 1]));
    }

    if (g == -1) cout << "0\n";
    else cout << g << "\n";
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