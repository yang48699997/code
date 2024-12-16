#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    vector<int> ans;

    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '|') continue;
        int cnt = 0;
        while (i < n && s[i] == '-') {
            cnt++;
            i++;
        }
        ans.push_back(cnt);
    }

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