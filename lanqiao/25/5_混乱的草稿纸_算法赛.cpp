#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >>n;


    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = n;

    int t = n;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == t) {
            ans--;
            t--;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}