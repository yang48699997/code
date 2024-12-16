#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int q(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;

    string s(n, '1');

    int l = 1;
    int res = 0;
    while (l < n) {
        res = q(1, l + 1);
        if (res == 0) {
            l++;
            continue;
        }
        for (int j = 1; j <= res; j++) {
            s[l - j] = '0';
        }
        break;
    }

    if (l == n) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }

    l++;
    while (l < n) {
        int now = q(1, l + 1);
        if (now == res) s[l] = '0';
        res = now;
        l++;
    }

    cout << "! " << s << endl;
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