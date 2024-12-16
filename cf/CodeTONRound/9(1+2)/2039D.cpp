#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    vector<int> ans(n + 1, -1);
    vector<set<int>> st(n + 1);

    for (int i = 1; i <= n; i++) {
        int now = 0;
        while (!st[i].empty() && *st[i].begin() == now) {
            st[i].erase(st[i].begin());
            now++;
        } 
        if (now >= m) {
            cout << "-1\n";
            return;
        }
        ans[i] = a[now];
        for (int j = i + i; j <= n; j += i) {
            st[j].insert(now);
        }
    }

    
    if (count(ans.begin(), ans.end(), -1) > 1) {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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