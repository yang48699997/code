#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int op = n - m;
    int need = 0;
    vector<int> ans;
    for (int i = n - m; i < n; i++) {
        if (a[i] > b[i - n + m]) {
            cout << "-1\n";
            return;
        }
        need += b[i - n + m] - a[i];
    }

    if (need > op) {
        cout << "-1\n";
        return;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        q.push(a[i]);
    }

    int lef = op - need;
    while (lef--) {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        q.push(x + 1);
        ans.push_back(x);
    }

    int p = 0;
    while (q.size() > m) {
        q.pop();
    }

    while (!q.empty()) {
        int x = q.top();
        q.pop();
        if (x > b[p]) {
            cout << "-1\n";
            return;
        }
        need -= b[p] - x;
        while (x < b[p]) {
            ans.push_back(x);
            x++;
        }
        p++;
    }

    cout << n - m << "\n";
    for (int i = 0; i < n - m; i++) {
        cout << ans[i] << " \n"[i == n - m - 1];
    }

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