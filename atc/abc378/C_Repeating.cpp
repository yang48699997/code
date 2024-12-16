#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (mp.count(x)) {
            cout << mp[x] << " \n"[i == n - 1];
        } else {
            cout << -1 << " \n"[i == n - 1];
        }
        mp[x] = i + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}