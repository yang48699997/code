#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> p(4);
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            p[0] = p[1] = p[2] = p[3] = 0;
            continue;
        }
        if (a[i] <= 2) {
            if (p[0] && p[1]) {
                p[0] = p[1] = p[2] = p[3] = 0;
                continue;
            }
            else {
                ans++;
                p[0] = p[1] = 1;
                p[2] = p[3] = 0;
            }
        } else if (a[i] <= 4) {
            if (p[0] && p[1]) {
                p[0] = p[1] = 0;
                p[2] = p[3] = 1;
            } else if (p[2] && p[3]) {
                p[0] = p[1] = 1;
                p[2] = p[3] = 0;
            } 
            ans++;
        } else {
            p[0] = p[1] = p[2] = p[3] = 0;
            ans++;
        }
    }
    cout << ans << "\n";
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