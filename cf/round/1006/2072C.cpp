#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    int p = x;
    int l = 0;

    auto check = [](int x, int y) -> bool {
        for (int i = 0; i < 30; i++) {
            if (x % 2 && y % 2 == 0) {
                return false;
            }
            x >>= 1;
            y >>= 1;
        }
        return true;
    };

    while (--n) {
        if (!check(l, x)) cout << l - 1 << " ";
        else {
            cout << l << " ";
            p -= (l & p);
            l++;
        }
    }
    if (check(l, x) && (l & p) == p) cout << l << "\n";
    else cout << p << "\n";
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