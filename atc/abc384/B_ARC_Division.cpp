#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, R;
    cin >> n >> R;

    for (int i = 0; i < n; i++) {
        int d, r;
        cin >> d >> r;
        if (d == 1) {
            if (R < 1600 || R > 2799) continue;
            R += r;
        } else {
            if (R < 1200 || R > 2399) continue;
            R += r;
        }
    }

    cout << R << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}