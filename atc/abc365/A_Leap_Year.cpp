#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int y;
    cin >> y;
    if (y % 4 == 0 && y % 100 != 0) {
        cout << "366\n";
    } else if (y % 400 == 0) {
        cout << "366\n";
    } else cout << "365\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}