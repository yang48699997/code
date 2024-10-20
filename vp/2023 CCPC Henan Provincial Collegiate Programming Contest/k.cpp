#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    auto check = [&](int x) -> int {
        if (x == 1) return 0;
        int p = sqrt(x);
        for (int i = 2; i <= p; i++) {
            if (x % i == 0) return 0;
        }
        return 1;
    };
    if (n & 1) {
        if (!check(n - 2)) {
            cout << "-1\n";
            return;
        }
    } else {
        if (!check(n - 1)) {
            cout << "-1\n";
            return;
        } else if (n > 3 && !check(n - 3)) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}