#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    map<string, int> mp;
    string me;
    cin >> me;
    mp[me]++;
    for (int i = 1; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    cout << mp[me] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}