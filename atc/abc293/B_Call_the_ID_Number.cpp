#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!v[i + 1]) v[x] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) cnt++;
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++) {
        if (!v[i]) cout << i << ' ';
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}