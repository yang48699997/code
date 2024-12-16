#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);

    for (int i = 0; i < m; i++) {
        int p;
        char g;
        cin >> p >> g;
        p--;

        if (v[p] || g == 'F') {
            cout << "No\n";
        } else {
            v[p] = 1;
            cout << "Yes\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}