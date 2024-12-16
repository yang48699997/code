#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(101);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int i = 0; i < 101; i++) {
        if (cnt[i] > 2) {
            cout << "yes\n";
            cout << i * 3 << "\n";
            return;
        }
    }

    cout << "no\n";
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