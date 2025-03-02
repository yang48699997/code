#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    string ans = string(n, '0');
    int l1 = 1, r1 = n;
    int l2 = 1, r2 = n;

    vector<int> lef(n);
    for (int i = 0; i < n; i++) {
        lef[i] = i;
    }

    int p = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            int ok = 0;
            for (int j = 0; j < n - i; j++) {
                if (s[j] == '1') ok = 1;
            }
            if (ok) {
                p = i;
                break;
            }
        }
    }

    if (p == n) {
        r1 = 1;
    } else {
        l1 = 1, r1 = n - p;
        string ans = s;
        for (int i = 0; i < n - p; i++) {
            if (s[i] == s[i + p]) {
                ans[i + p] = '0'; 
            } else ans[i + p] = '1';
        }

        for (int i = 0; i <= p; i++) {
            string res = s;
            for (int j = 0; j < n - p; j++) {
                if (s[i + j] == s[p + j]) res[p + j] = '0';
                else res[p + j] = '1';
            }

            if (res > ans) {
                l1 = i + 1;
                r1 = i + n - p;
                ans = res;
            }
        }
    }
    cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
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