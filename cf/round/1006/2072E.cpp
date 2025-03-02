#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int k;
    cin >> k;

    vector<array<int, 2>> p;

    int x = 0;
    int y = 0;

    while (k) {
        p.push_back({x++, y});
        int now = 1;
        while (now <= k) {
            p.push_back({x++, y});
            k -= now++;
        }
        y--;
    }

    cout << p.size() << "\n";
    for (int i = 0; i < p.size(); i++) {
        cout << p[i][0] << ' ' << p[i][1] << "\n";
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