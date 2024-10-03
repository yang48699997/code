#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

ll cr(ll n, int pp) {
    ll l = 1, r = sqrt(n) + 1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        int ok = 0;
        ll now = mid;
        for (int i = 1; i < pp; i++) {
            if (now >= n / mid) {
                ok = 1;
                break;
            } else {
                now *= mid;
            }
        }
        if (now >= n) ok = 1;
        if (ok) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}


ll cal(ll n, int pp) {
    ll ans = 0;
    ll l = 1, r = cr(n, pp);
    while (l <= r) {
        ll mid = (l + r) / 2;
        int ok = 0;
        ll now = mid;
        for (int j = 1; j < pp; j++) {
            if (now > n / mid) {
                ok = 1;
                break;
            } else {
                now *= mid;
            }
        }
        if (now > n) ok = 1;
        if (ok) r = mid - 1;
        else l = mid + 1;
    }
    ans += r - 1;
    return ans; 
}

ll f(ll n) {
    const int mx = 61;
    ll ans = 1;
    for (int i = 2; i < mx; i++) {
        int now = i;
        int op = -1;
        int ok = 1;
        for (int j = 0; j < 17; j++) {
            if (now % p[j]) continue;
            op *= -1;
            int cnt = 0;
            while (now % p[j] == 0) {
                cnt++;
                now /= p[j];
            }
            if (cnt != 1) ok = 0;
        }
        if (ok) ans += cal(n, i) * op;
        // cerr << i << " " << op << "\n";
        // cerr << cal(n, i) << "\n";
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    cout << f(n) << "\n";
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