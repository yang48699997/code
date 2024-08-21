#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(k), c(k);
    for (int i = 0; i < k; i++) cin >> x[i];
    for (int i = 0; i < k; i++) cin >> c[i];

    string s = "abc";
    int now = 3;
    int l = 3;
    int pre = 0;
    int p = 0;
    for (int i = 0; i < k; i++) {
        int left = c[i] - now;
        now = c[i];
        if (left > x[i] - pre || c[i] > x[i]) {
            cout << "NO\n";
            return;
        } 
        pre = x[i];
        while (l < x[i]) {
            if (left) {
                s += 'a' + i + 3;
                left--;
            } else {
                s += 'a' + p;
                p = (p + 1) % 3;
            }
            l++;
        }
    }
    while (l < n) {
        s += 'a' + p;
        p = (p + 1) % 3;
        l++;
    }
    cout << "YES\n";
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}