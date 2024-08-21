#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll cal(int l) {
    ll res = 0;
    int now = 1;
    int cnt = 1;
    while (now <= l) {
        int nxt = now * 3 - 1;
        res += (min(nxt, l) - now + 1) * cnt;
        cnt++;
        now = now * 3;
    }
    return res;
}

void solve() {
    int l, r;
    cin >> l >> r;
    ll ans = 2;
    int now = 3;
    while (now <= l) {
        ans += 2;
        now *= 3;
    }
    ans += cal(r) - cal(l);
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