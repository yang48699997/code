#include <bits/stdc++.h>
using namespace std;

using ll = __int128;

ll gcd(ll x, ll y) {
    while (y) {
        ll t = y;
        y = x % y;
        x = t;
    };
    return x;
};

void print(ll x) {
    string s;
    while (x) {
        char c = '0' + x % 10;
        s += c;
        x /= 10;
    } 
    reverse(s.begin(), s.end());
    cout << s;
}

void solve() {
    long long x, y;
    cin >> x >> y;
    if (x % y == 0) {
        cout << y << " " << x / y << "\n";
        return;
    }
    ll g = gcd(x, y);

    ll p = x / g;
    ll q = y / g;
    ll ans2 = y;
    ll ans1 = p * q * g; 
    if (q != 1 && q % 2 == 1) {
        ans1 *= 2;
    }
    print(ans2);
    cout << " " ;
    print(ans1 / ans2);
    cout << "\n";
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