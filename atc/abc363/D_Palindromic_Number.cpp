#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    if (n <= 10) {
        cout << n - 1 << "\n";
        return;
    }    
    vector<ll> power(19, 1);
    for (int i = 1; i <= 18; i++) {
        power[i] = power[i - 1] * 10;
    } 
    ll sum = 10;
    int p = 2;
    string s;
    while (1) {
        ll t = 9 * power[p / 2 - 1 + p % 2];
        if (sum + t < n) sum += t;
        else {
            n -= sum + 1;
            n += power[p / 2 - 1 + p % 2];
            s = to_string(n);
            int m = s.length() - 1;
            if (p % 2) m--;
            for (int i = m; i >= 0; i--) s += s[i];
            break;
        }
        p++;
    }
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}