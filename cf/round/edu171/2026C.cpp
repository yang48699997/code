#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    ll ans = 0;
    queue<int> q;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            if (q.empty()) {
                ans += i + 1;
            } else {
                ans -= q.front();
                q.pop();
                ans += i + 1;
            }
        } else {
            q.push(i + 1);
            ans += i + 1;
        }
    }

    int lef = q.size() / 2;
    while (lef--) {
        ans -= q.front();
        q.pop();
    }

    cout << ans << "\n";
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