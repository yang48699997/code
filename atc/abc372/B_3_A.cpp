#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int m;
    cin >> m;

    vector<int> ans;

    for (int i = 0; i <= 10; i++) {
        if (m % 3 == 1) {
            ans.push_back(i);
        } else if (m % 3 == 2) {
            ans.push_back(i);
            ans.push_back(i);
        }
        m /= 3;
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}