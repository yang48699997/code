#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int T;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (r - l + 1 > 100) {
            cout << "YES\n";
            continue;
        }
        int len = r - l + 1;
        vector<int> b(len);

        for (int i = 0; i < len; i++) b[i] = a[i + l];
        sort(b.begin(), b.end());
        int ok = 0;
        int L = 1e9, R = -1;
        for (int i = 0; i < len - 2; i++) {
            if (b[i] + b[i + 1] > b[i + 2]) {
                L = min(L, i);
                R = max(R, i);
            }
        }
        if (R - L >= 3) ok = 1;
        for (int i = 0; i < len - 5; i++) {
            if (b[i] + b[i + 2] > b[i + 3] && b[i + 1] + b[i + 4] > b[i + 5]) ok = 1;
            if (b[i + 1] + b[i + 2] > b[i + 3] && b[i] + b[i + 4] > b[i + 5]) ok = 1;
            if (b[i] + b[i + 1] > b[i + 3] && b[i + 2] + b[i + 4] > b[i + 5]) ok = 1;
            if (b[i + 2] + b[i + 3] > b[i + 4] && b[i] + b[i + 1] > b[i + 5]) ok = 1;
            if (b[i + 1] + b[i + 3] > b[i + 4] && b[i] + b[i + 2] > b[i + 5]) ok = 1;
            if (b[i] + b[i + 3] > b[i + 4] && b[i + 1] + b[i + 2] > b[i + 5]) ok = 1;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}