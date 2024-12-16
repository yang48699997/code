#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(n);
    b[0] = a[0];

    vector<int> cnt(n + 1);
    int l = 1;
    cnt[a[0]]++;
    int mx = 1;

    for (int i = 1; i < n; i++) {
        while (cnt[a[i]] < mx) {
            b[l++] = a[i];
            cnt[a[i]]++;
        }
    }

    priority_queue<array<int, 2>> q;
    for (int i = 1; i <= n; i++) {
        q.push({-cnt[i], i});
    }

    while (l < n) {
        auto [c, p] = q.top();
        q.pop();
        c--;
        b[l++] = p;
        q.push({c, p});
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1];
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