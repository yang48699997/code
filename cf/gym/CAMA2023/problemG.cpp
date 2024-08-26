#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;

void solve() {
    ll s, x;
    cin >> s >> x;
    i128 sum = 0;
    vector<int> a(30);
    i128 p = 1;
    for (int i = 0; i < 30; i++) cin >> a[i];
    int ans = 0;
    int ok = 1;
    for (int i = 0; i < 30; i++) {
        p *= 10;
        int now = a[i] & 1;
        if ((x >> i) ^ now) {
            a[i]++;
        }
        sum += p * a[i];
        if ()
    }
    for (int i = 0; i < 30; i++) {
        ans = max(ans, a[i]); 
    }
    if (sum != s) {
        cout << "-1\n";
        return;
    } else cout << ans << "\n";

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