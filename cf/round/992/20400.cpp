#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> cnt(k);
    vector<int> p(k);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cnt[x % k]++;
        p[x % k] = i + 1;
    }

    for (int i = 0; i < k; i++) {
        if (cnt[i] == 1) {
            cout << "YES\n";
            cout << p[i] << "\n";
            return;
        }
    }

    cout << "NO\n";
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