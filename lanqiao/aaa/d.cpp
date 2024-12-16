#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(n + 1, 1);
    while (q--) {
        int x;
        cin >> x;
        cnt[x] = cnt[x] * 10 % 24;
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) continue;
        for (int j = i; j <= n; j += i) {
            a[j] = a[j] * cnt[i] % 24;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}