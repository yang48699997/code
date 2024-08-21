#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    
    int ans = 0;
    int l = n + 1;
    int mi = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > mi && a[i] < l) {
            ans++;
            l = a[i];
        } else {
            mi = min(mi, a[i]);
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