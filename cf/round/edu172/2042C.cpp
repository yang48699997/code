#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    ll now = 0;
    vector<ll> p;
    for (int i = n - 1; i >= 0; i--) {
        p.push_back(now);
        if (s[i] == '0') now--;
        else now++;
    }

    ll res = 0;
    sort(p.rbegin(), p.rend());
    for (int i = 0; i < n; i++) {
        res += p[i];
        if (res >= k) {
            cout << i + 2 << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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