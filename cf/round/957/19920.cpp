#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 5; i++) {
        sort(a.begin(), a.end());
        a[0]++;
    }
    for (int i = 1; i < 3; i++) a[0] *= a[i];
    cout << a[0] << "\n";
    
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