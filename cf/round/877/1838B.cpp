#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[x] = i + 1;
    }
    if (p[2] < p[n]) {
        if (p[1] < p[2]) cout << p[2] << " " << p[n] << "\n";
        else if (p[1] < p[n]) cout << p[1] << " " << p[n] << "\n";
        else cout << p[2] << " " << p[2] << "\n";
    } else {
        if (p[1] < p[n]) cout << p[2] << " " << p[2] << "\n";
        else if (p[1] < p[2]) cout << p[1] << " " << p[n] << "\n";
        else cout << p[2] << " " << p[n] << "\n";
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