#include <bits/stdc++.h>
using namespace std;

int T;
const int mx = (1 << 20);

int pri[mx], p[mx];
int tot;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        cout << "1\n";
        return;
    } else if (n == 2) {
        cout << "2\n";
        cout << "1 2\n";
        return;
    } else if (n == 3) {
        cout << "2\n";
        cout << "1 2 2\n";
        return;
    } else if (n == 4) {
        cout << "3\n";
        cout << "1 2 2 3\n";
        return;
    } else if (n == 5) {
        cout << "3\n";
        cout << "1 2 2 3 3\n";
        return;
    }
    vector<int> ans(n + 1);
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 2; i <= n; i += 2) {
        ans[i] = 2;
    }
    for (int i = 2; i <= n; i += 2) {
        int nxt = (i ^ 2);
        if (nxt > i || nxt == 0) continue;
        if (ans[nxt] == 2) ans[i] = 4;
    }
    for (int i = 3; i <= n; i += 2) {
        ans[i] = 1;
    }
    for (int i = 3; i <= n; i += 2) {
        int nxt = (i ^ 2);
        if (nxt > i || nxt == 0) continue;
        if (ans[nxt] == 1) ans[i] = 3;
    }
    cout << 4 << "\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    tot = 0;
    for (int i = 0; i < mx; i++) {
        pri[i] = p[i] = 0;
    }
    for (int i = 2; i < mx; i++) {
        if (!pri[i]) {
            p[tot++] = i;
        }
        for (int j = 0; i * p[j] < mx; j++) {
            pri[i * p[j]] = 1;
            if (i % p[j] == 0) break; 
        }
    }
    while (T--) {
        solve();
    }
    return 0;
}