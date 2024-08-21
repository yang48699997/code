#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<int> q;

    for (int i = n - 1; i >= 0; i--) {
        if (q.empty() || q.top() <= a[i]) {
            q.push(a[i]);
            continue;
        }
        while (q.top() > a[i]) {
            int x = q.top();
            x--;
            a[i]++;
            q.pop();
            q.push(x);
        }
        q.push(a[i]);
    }
    ll ans = 1;
    while (!q.empty()) {
        int x = q.top();
        q.pop();
        ans = ans * x % mod;
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