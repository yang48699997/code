#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    int p = 1;
    while (n) {
        if (n % 10 != 0) {
            ans.push_back(n % 10 * p);
        }
        n /= 10;
        p *= 10;
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " \n"[i == ans.back()];
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