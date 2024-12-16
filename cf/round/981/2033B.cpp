#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n * 2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x < 0) cnt[i + n - 1 - j] = max(cnt[i + n - 1 - j], -x);
        }
    }

    cout << accumulate(cnt.begin(), cnt.end(), 0) << "\n";
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