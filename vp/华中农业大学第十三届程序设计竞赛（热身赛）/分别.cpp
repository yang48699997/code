#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int t;
    cin >> t;
    vector<ll> cnt(2);

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            cnt[0] += x;
        } else {
            int a, b;
            cin >> a >> b;
            cnt[0] -= a;
            cnt[1] += b;
        }
        if (max(cnt[0], cnt[1]) > m) {
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}