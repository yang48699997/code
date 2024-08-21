#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == '_') {
            if (stk.empty()) stk.push(i);
            else {
                ans += i - stk.top();
                stk.pop();
            }
        } else {
            if (s[i] == '(') stk.push(i);
            else {
                ans += i - stk.top();
                stk.pop();
            }
        }
    }
    cout << ans << "\n";
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