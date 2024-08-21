#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int q(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int l = 1, r = 1000;
    while (l <= r) {
        int d = (r - l) / 3;
        int x = l + d;
        int y = r - d;
        int res = q(x, y);
        if (res == x * y) {
            l = y + 1;
        } else if (res == (x + 1) * (y + 1)){
            r = x - 1;
        } else {
            l = x + 1;
            r = y - 1;
        }
    }    
    cout << "! " << l << endl;
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