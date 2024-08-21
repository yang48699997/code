#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, s, r1, r2;
    cin >> n >> s >> r1 >> r2;
    s--;

    vector<vector<int>> e(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }   

    if (r1 * 2 >= r2) {
        cout << "Kangaroo_Splay\n";
        return;
    }
    queue<int> q;
    vector<int> d(n);
    q.push(s);
    d[s] = 1;
    int mx = 1;
    int last = s;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nxt : e[x]) {
            if (d[nxt]) continue;
            d[nxt] = d[x] + 1;
            q.push(nxt);
            mx = max(d[nxt], mx);
            last = nxt;
        }
    }
    for (int i = 0; i < n; i++) d[i] = 0;
    d[last] = 1;
    q.push(last);
    mx = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nxt : e[x]) {
            if (d[nxt]) continue;
            d[nxt] = d[x] + 1;
            q.push(nxt);
            mx = max(d[nxt], mx);
        }
    }
    // cerr << mx << "\n";
    mx--;
    if (mx > r1 * 2) {
        cout << "General_Kangaroo\n";
        return;
    } else {
        cout << "Kangaroo_Splay\n";
        return;
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