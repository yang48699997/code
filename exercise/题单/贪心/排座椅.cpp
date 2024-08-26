#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k, l, d;
    cin >> n >> m >> k >> l >> d;
    vector<int> c(n), r(m);
    vector<int> col(n - 1), row(m - 1);
    iota(col.begin(), col.end(), 1);
    iota(row.begin(), row.end(), 1);

    while (d--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            r[min(y1, y2)]++;
        } else {
            c[min(x1, x2)]++;
        }
    }

    sort(col.begin(), col.end(), [&](int x1, int x2) {
        return c[x1] > c[x2];
    });
    sort(row.begin(), row.end(), [&](int x1, int x2) {
        return r[x1] > r[x2];
    });

    col.resize(k);
    row.resize(l);
    sort(col.begin(), col.end());
    sort(row.begin(), row.end());
    for (int i = 0; i < k; i++) cout << col[i] << " \n"[i == k - 1]; 
    for (int i = 0; i < l; i++) cout << row[i] << " \n"[i == l - 1]; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}