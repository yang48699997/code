#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int h;
    ll n;
    cin >> h >> n;
    ll ans = 0;
    vector<ll> power(h + 1);
    power[0] = 1;
    for (int i = 1; i <= h; i++) {
        power[i] = power[i - 1] * 2;
    } 

    while (h) {
        if (n <= power[h] / 2) {
            ans++;
            n = power[h] / 2 - n + 1;
            h--;
        } else {
            ans += power[h];
            n -= power[h] / 2;
            h--;
        }
    }


    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}