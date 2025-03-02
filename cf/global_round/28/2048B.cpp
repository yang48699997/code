#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    int l = 1, r = n;
    int p = k - 1;

    a[p] = l++;

    for (int i = 0; i < n; i++) {
        if (abs(i - p) < k) {
            if (i == p) continue;
            a[i] = r--;
        } else if (i != p) {
            a[i] = l++;
            p = i;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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