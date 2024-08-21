#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    int ans = 0;
    if (r1 >= r2) {
        ans = r2 - l2 + 2;
        if (l1 == l2) ans--;
        if (r1 == r2) ans--;
    } else if (l2 > r1){
        ans = 1;
    } else {
        ans = r1 - l2 + 2;
        if (l1 == l2) ans--;
    }
    cout << ans << "\n";
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