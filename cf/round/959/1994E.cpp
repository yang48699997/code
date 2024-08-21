#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        a[i] = n;
        int x;
        for (int i = 0; i < n - 1; i++) cin >> x;
    }
    int ans = 0;
    for (int i = 20; i >= 0; i--) {
        int cnt = 0;
        for (int l = 0; l < k; l++) {
            if (1 << i & a[l]) cnt++;
        }
        if (cnt > 1) {
            ans |= (1 << i) - 1;
            ans |= (1 << i);
            break;
        }
        else if (cnt) ans |= (1 << i);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}