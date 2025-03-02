#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    if (k / x + (k % x != 0) < n) {
        cout << "-1\n";
        return;
    }

    if (k / x > n) {
        cout << "-1\n";
        return;
    }


    int l = x;
    if (k / x == n) {
        l = x - k % x;
    }
    int r = l + k - 1;
    cout << l << " " << r << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}