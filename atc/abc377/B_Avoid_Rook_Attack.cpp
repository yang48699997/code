#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    vector<int> r(8), c(8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') r[i] = c[j] = 1;
        }
    }

    cout << count(r.begin(), r.end(), 0) * count(c.begin(), c.end(), 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}