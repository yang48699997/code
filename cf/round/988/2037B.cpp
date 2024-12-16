#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!v[i]) continue;
        if ((n - 2) % i) continue;
        v[i]--;
        if (v[(n - 2) / i]) {
            cout << i << " " << (n - 2) / i << "\n";
            return;
        }
        v[i]++;
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