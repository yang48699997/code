#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll powMod(ll x, ll y) {
    ll res = 1;
    while (y) {
        if(y & 1)res = res * x;
        x = x * x;
        y >>= 1;
    };
    return res;
};

void solve(){
    int n;
    cin >> n;
    int ans = __lg(n);
    if (powMod(2, ans) < n) ans++;
    ll pre = 2;
    vector<int> p(ans, 1);
    for (int i = 1; i < ans; i++) {
        ll l = 1, r = pre;
        while (l <= r) {
            ll mid = (l + r) / 2;
            int ok = 0;
            ll sum = pre + mid;
            if (sum >= n) ok = 1;
            for (int j = i + 1; j < ans; j++) {
                sum *= 2;
                if (sum >= n) {
                    ok = 1;
                    break;
                }
            }
            if (ok) r = mid - 1;
            else l = mid + 1;
        }
        p[i] = l;
        pre += l;
    }
    cout << ans << "\n";
    for (int i = 0; i < ans; i++) {
        cout << p[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}