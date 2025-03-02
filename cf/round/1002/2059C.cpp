#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> a(n, vector<int> (n));
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int p = 0;
        while (!a[i].empty() && a[i].back() == 1) {
            p++;
            a[i].pop_back();
        }
        cnt[p]++;
    }

    for (int i = n - 1; i >= 0; i--) {
        cnt[i] += cnt[i + 1];
    }

    int ans = 1;
    for (int i = n - 1; i > 0; i--) {
        int p = 0;
        int ok = 1;
        for (int j = i; j > 0; j--) {
            if (cnt[j] - p <= 0) ok = 0; 
            p++;
        }
        if (ok) {
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << ans << "\n";
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