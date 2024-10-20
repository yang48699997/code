#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mx = 1e6 + 5;
int pre[mx];

void init() {
    vector<int> cnt(mx);
    for (int i = 0; i < mx; i++) {
        pre[i] = 0;
    }
    for (int i = 1; i < mx; i++) {
        for (int j = i; j < mx; j += i) {
            cnt[j]++;
        }
        pre[i] = pre[i - 1];
        if (cnt[i] <= 4) pre[i]++;
    }
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    init();
    while (T--) {
        solve();
    }
    return 0;
}