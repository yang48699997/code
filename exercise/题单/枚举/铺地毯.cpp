#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p, d;
    for (int i = 0; i < n; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        p.emplace_back(a, b);
        d.emplace_back(x, y);
    } 
    int tx, ty;
    cin >> tx >> ty;
    for (int i = n - 1; i >= 0; i--) {
        if (p[i].first <= tx && p[i].first + d[i].first >= tx && p[i].second <= ty && p[i].second + d[i].second >= ty) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}