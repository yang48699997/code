#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> p(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[(a[i] - 1) % k].push_back(i);
    }
    
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < p[i].size(); j++) {
            if (p[i][j] % k != i) cnt++;
        }
    }

    if (cnt == 0) cout << "0\n";
    else if (cnt == 2) cout << "1\n";
    else cout << "-1\n";

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