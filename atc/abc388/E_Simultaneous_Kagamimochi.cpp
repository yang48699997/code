#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = n / 2;

    while (l <= r) {
        int mid = (l + r) / 2;
        int ok = 1;

        for (int i = 0; i < mid; i++) {
            if (a[i] * 2 > a[n - mid + i]) {
                ok = 0;
                break;
            }
        }

        if (ok) l = mid + 1;
        else r = mid - 1;
    }
    
    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}