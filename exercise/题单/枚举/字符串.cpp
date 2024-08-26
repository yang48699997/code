#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = n;
    vector<int> v(26);
    int cnt = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (!v[s[i] - 'a']) {
            cnt++;
        }
        v[s[i] - 'a']++;
        while (cnt == 26) {
            ans = min(ans, i - l + 1);
            v[s[l] - 'a']--;
            if (!v[s[l] - 'a']) cnt--;
            l++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}