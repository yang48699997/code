#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 5);
    for (int i = 0; i < n * 5; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    double ans = 0;
    for (int i = n; i< n * 4; i++) {
        ans += a[i];
    }
    ans /= n * 3;
    cout << fixed << setprecision(10) << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}