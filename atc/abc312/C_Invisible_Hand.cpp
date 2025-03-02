#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> p;
    for (int i = 0; i < n; i++) {
        p.push_back(a[i]);
        p.push_back(a[i] + 1);
    }
    for (int i = 0; i < m; i++) {
        p.push_back(b[i]);
        p.push_back(b[i] + 1);
    }

    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    int r1 = n - 1, r2 = m - 1;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 1e9 + 1;
    for (int i = p.size() - 1; i >= 0; i--) {
        while (r1 >= 0 && a[r1] > p[i]) r1--;
        while (r2 >= 0 && b[r2] >= p[i]) r2--;

        if (r1 + 1 >= m - r2 - 1) ans = p[i];
    }
    

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}