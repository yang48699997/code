#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    } 
    if (n % 2 == 1) {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i + 1 << " " << i << " \n"[i == n - 1];
    }

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