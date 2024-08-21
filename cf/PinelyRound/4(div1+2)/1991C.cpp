#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans;
    sort(a.begin(), a.end());
    while (a.back() != 0) {
        if (a[0] == 0 && a.back() == 1) {
            cout << "-1\n";
            return;
        }
        int mid = (a[0] + a.back()) / 2;
        ans.push_back(mid);
        for (int i = 0; i < n; i++) {
            a[i] = abs(mid - a[i]);
        }
        sort(a.begin(), a.end());
    }
    cout << ans.size() << "\n";
    for (int i = 0; i <ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
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