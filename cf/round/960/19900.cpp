#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    int cnt = 0;
    int p = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] == p) cnt++;
        else {
            if (cnt & 1) {
                cout << "YES\n";
                return;
            }
            cnt = 1;
            p = a[i];
        }
    }
    if (cnt & 1) cout << "YES\n";
    else cout << "NO\n";
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