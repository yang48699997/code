#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int q;
    cin >> q;

    auto check = [](auto &&self, ll t) -> int {
        if (t == 1) return 0;
        ll half = 1LL << __lg(t);
        if (half == t) half /= 2;

        if (t <= half) return self(self, t);
        else return 1 ^ self(self, t - half);
    };

    while (q--) {
        ll k;
        cin >> k;
        k--;

        ll t = k / n + 1;
        int lef = k % n;

        char ans = (s[lef] ^ (check(check, t) * 32));

        cout << ans << " \n"[q == 0];
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}