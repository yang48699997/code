#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    sort(p.begin(), p.end(), [&](auto& p1, auto& p2){
        if (min(p1[0], p1[1]) != min(p2[0], p2[1])) {
            return min(p1[0], p1[1]) < min(p2[0], p2[1]);
        }
        return max(p1[0], p1[1]) < max(p2[0], p2[1]);
    });

    for (int i = 0; i < n; i++) {
        cout << p[i][0] << " " << p[i][1] << " \n"[i == n - 1];
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