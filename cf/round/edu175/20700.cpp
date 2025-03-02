#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> p(15);
    for (int i = 0; i < 15; i++) {
        if (i % 3 == i % 5) {
            p[i]++;
        }
        if (i) p[i] += p[i - 1];
    }

    cout << n / 15 * p[14] + p[n % 15] << "\n";
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