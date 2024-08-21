#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    for (int i = 0; i <= n; i++) {
        int cnt = 0;
        for (int j = i; j >= 0; j--) cnt += a[j];
        cnt = n - cnt;
        if (cnt < i) continue;
        int ok = 1;
        for (int j = i + 1; j <= n; j++) {
            if (j > cnt) break;
            if (a[j]) ok = 0;
        }
        if (ok) {
            cout << cnt << "\n";
            return;
        }
    }

    cout << "-1\n";
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