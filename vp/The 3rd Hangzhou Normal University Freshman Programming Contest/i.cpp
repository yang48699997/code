#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        ll x;
        cin >> x;
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        if (res >= 16 || res == 6) cnt++;
    }
    if (cnt == 0) cout << "Bao Bao is so Zhai......\n";
    else if (cnt == 1) cout << "Oh dear!!\n";
    else if (cnt == 2) cout << "BaoBao is good!!\n";
    else if (cnt == 3) cout << "Bao Bao is a SupEr man///!\n";
    else cout << "Oh my God!!!!!!!!!!!!!!!!!!!!!\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}