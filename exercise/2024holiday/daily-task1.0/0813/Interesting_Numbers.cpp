#include <bits/stdc++.h>
using namespace std;

using ll = __int128;
const ll q = 1e16;

void print(ll x) {
    if (x == 0) {
        cout << "0\n";
        return;
    }
    string s;
    while (x) {
        s += x % 10 + '0';
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

ll cal(ll l, ll r) {
    ll r1 = q;
    ll l1 = 0;
    while (l1 <= r1) {
        ll mid = (r1 - l1) / 2 + l1;
        if (mid * mid < l) l1 = mid + 1;
        else r1 = mid - 1;
    }
    ll res = l1;
    r1 = q;
    l1 = 0;
    while (l1 <= r1) {
        ll mid = (r1 - l1) / 2 + l1;
        if (mid * mid > r) r1 = mid - 1;
        else l1 = mid + 1;
    }
    res = r1 - res + 1;
    return res;
};



void solve() {
    int n;
    cin >> n;
    string x, y;
    cin >> x >> y;
    ll lef1 = 0, m1 = 0;
    for (int i = 0; i < n / 2; i++) {
        lef1 = lef1 * 10 + x[i] - '0';
    }
    for (int i = n / 2; i < n; i++) {
        m1 = m1 * 10 + x[i] - '0';
    }
    ll lef2 = 0, m2 = 0;
    for (int i = 0; i < n / 2; i++) {
        lef2 = lef2 * 10 + y[i] - '0';
    }
    for (int i = n / 2; i < n; i++) {
        m2 = m2 * 10 + y[i] - '0';
    }
    ll mx = 1;
    for (int i = 0; i < n / 2; i++) mx *= 10;
    if (lef1 == lef2) {
        ll ans = cal(m1, m2);
        print(ans);
        return;
    }
    ll ans = 0;
    if (cal(lef1, lef1) == 1) {
        ans += cal(m1, mx - 1);
        lef1++;
    }
    if (cal(lef2, lef2) == 1) {
        ans += cal(0, m2);
        lef2--;
    }
    if (lef1 <= lef2) {
        ans += cal(lef1, lef2) * cal(0, mx - 1);
    }
    print(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}