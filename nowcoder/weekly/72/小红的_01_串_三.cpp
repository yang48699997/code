#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    if (k == 0) {
        if (a && b) cout << "-1\n";
        else {
            for (int i = 0; i < a; i++) cout << '0';
            for (int i = 0; i < b; i++) cout << '1';
            cout << "\n";
        }
        return;
    }

    int p = min(a, b) * 2 - (a == b);
    if (p < k) cout << "-1\n";
    else {
        vector<int> p(k + 1);
        int l = (k + 1) / 2 + (k +  1) % 2;
        int r = k + 1 - l;
        if (a >= l && b >= r) {
            int lef1 = a - l;
            int lef2 = b - r;
            for (int i = 0; i < k + 1; i++) {
                if (i & 1) {
                    cout << '1';
                    while (lef2 > 0) {
                        cout << '1';
                        lef2--;
                    }
                } else {
                    cout << '0';
                    while (lef1 > 0) {
                        cout << '0';
                        lef1--;
                    }
                }
            }
        } else {
            int lef1 = b - l;
            int lef2 = a - r;
            for (int i = 0; i < k + 1; i++) {
                if (i & 1) {
                    cout << '0';
                    while (lef2 > 0) {
                        cout << '0';
                        lef2--;
                    }
                } else {
                    cout << '1';
                    while (lef1 > 0) {
                        cout << '1';
                        lef1--;
                    }
                }
            }
        }
        cout << "\n";
    }

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