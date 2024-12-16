#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();

    vector<string> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] <= t[i]) continue;
        s[i] = t[i];
        ans.push_back(s);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == t[i]) continue;
        s[i] = t[i];
        ans.push_back(s);
    }

    cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}