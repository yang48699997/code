#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> p(1);
    int cnt = b;
    if (a < c) {
        p[0] = 1;
    }
    while (cnt--) {
        p.push_back(p.back() ^ 1);
    }
    for (int i = 0; i < p.size(); i++) {
        cout << p[i];
        if (p[i]) {
            while (c) {
                cout << p[i];
                c--;
            }
        } else {
            while (a) {
                cout << p[i];
                a--;
            }
        }
    }
    cout << "\n";
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