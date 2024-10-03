#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mx = 1e6 + 5;
int sg[mx];

void init() {
    sg[0] = 0;
    for (int i = 1; i < mx; i++) {
        int now = i;
        int res = 0;
        while (now) {
            res += now % 10;
            now /= 10;
        }
        int mi = sg[i - 1];
        for (int j = 1; j <= res; j++) {
            mi = min(mi, sg[i - j]);
        }
        if (mi == 0) sg[i] = 1;
        else sg[i] = 0;
    }
}

void solve() {
    int x;
    cin >> x;
    if (sg[x]) cout << "A\n";
    else cout << "B\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    init();
    while (T--) {
        solve();
    }
    return 0;
}