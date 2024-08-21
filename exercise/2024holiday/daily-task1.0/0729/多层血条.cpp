#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, m;
    cin >> n >> m;
    int p, d;
    cin >> p >> d;
    int j = min(m, p);
    vector<char> k = {'A', 'B', 'C', 'D', 'E'};
    string t = "+";
    for (int i = 0; i < m; i++) t += "-";
    t += "+";
    string ans = "|";
    for (int i = 0; i < m; i++) ans += " ";
    ans += "|";
    int l = p % j;
    p -= l;
    int dd = p / j % 5;
    dd = (dd - 1 + 5) % 5;
    if (p > 0) for (int i = 1; i <= j; i++) ans[i] = k[dd];
    dd = (dd + 1) % 5;
    for (int i = 1; i <= l; i++) ans[i] = k[dd];
    for (int i = l; i > 0; i--) {
        if (d) {
            ans[i] = '.';
            if (p == 0) ans[i] = ' ';
            d--;
        } else {
            break;
        }
    }
    for (int i = j; i > l; i--) {
        if (d) {
            ans[i] = '.';
            if (p == 0) ans[i] = ' ';
            d--;
        } else {
            break;
        } 
    }
    cout << t << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans << "\n";
    }
    cout << t << "\n";
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