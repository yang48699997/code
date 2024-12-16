#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<set<int>> r(n), c(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            r[i].insert(j);
            c[j].insert(i);
        }
    }
    int cnt = n * m;

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (r[x].count(y)) {
            cnt--;
            r[x].erase(y);
            c[y].erase(x);
            continue;
        }

        auto it = r[x].lower_bound(y);
        if (it != r[x].end()) {
            cnt--;
            int ny = *it;
            r[x].erase(ny);
            c[ny].erase(x);
        }
        it = r[x].lower_bound(y);
        if (it != r[x].begin()) {
            it = prev(it);
            cnt--;
            int ny = *it;
            r[x].erase(ny);
            c[ny].erase(x);
        }
        it = c[y].upper_bound(x);
        if (it != c[y].end()) {
            cnt--;
            int nx = *it;
            c[y].erase(nx);
            r[nx].erase(y);
        }
        it = c[y].lower_bound(x);
        if (it != c[y].begin()) {
            it = prev(it);
            cnt--;
            int nx = *it;
            c[y].erase(nx);
            r[nx].erase(y);
        }

    }

    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}