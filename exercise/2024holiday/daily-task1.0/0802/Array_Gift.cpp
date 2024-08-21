#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int gcd(int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    while (y) {
        int t = y;
        y = x % y;
        x = t;
    };
    return x;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    const int mx = 1e6 + 5;
    vector<int> cnt(mx);
    int g = -1;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        g = gcd(g, a[i]);
    }

    if (cnt[g]) {
        cout << n - 1 << "\n";
        return;
    }

    vector<int> b;
    for (int i = 1; i < mx; i++) {
        if (cnt[i] == 0) continue;
        cnt[i] = 1;
        b.push_back(i);
        for (int j = i + i; j < mx; j += i) {
            cnt[j] = 0;
        }
    }
    sort(a.begin(), a.end());
    int m = b.size();
    int ok = 0;
    for (int i = 0; i < m; i++) {
        int g2 = -1;
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            g2 = gcd(g2, b[j]);
        }
        cnt[b[i]]--;
        if (g2 == - 1 || b[i] < g2 || cnt[g2]) ok = 1;
        cnt[b[i]]++;
    }
    if (ok) {
        cout << n << "\n";
        return;
    }

    ok = 0;
    for (int i = 1; i < n; i++) {
        int g3 = -1;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            g3 = gcd(g3, a[j]);
        }
        for (int j = 0; j < i; j++) {
            if (a[i] % a[j] != 0 && g3 % (a[i] % a[j]) == 0) {
                ok = 1;
            }
        }
    }
    if (ok) {
        cout << n << "\n";
        return;
    }
    
    cout << n + 1 << "\n";
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