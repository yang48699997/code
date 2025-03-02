#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int l = n, r = -1;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            l = min(l, i);
            r = max(r, i);
        }
    }

    if (l == n) {
        cout << "0\n";
        return;
    }

    int ans = r - l + 1;
    vector<int> c1(26), c2(26);
    for (int i = l; i <= r; i++) {
        c1[s[i] - 'a']++;
        c2[s[n - i - 1] - 'a']++;
    }

    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < 26; i++) {  
        if (c1[i] >= c2[i]) cnt++;
    }
    
    if (cnt == 26) {
        cout << ans << "\n";
        return;
    }

    for (int i = r + 1; i < n / 2; i++) {
        ans++;
        c1[s[i] - 'a']++;
        c2[s[n - i - 1] - 'a']++;
    }
    cnt = 0;
    
    vector<int> c3 = c1, c4 = c2;
    for (int i = 0; i < 26; i++) {
        if (c1[i] >= c2[i]) cnt++;
        if (c4[i] >= c3[i]) cnt2++;
    }
    
    for (int i = n / 2; i < n; i++) {
        ans++;
        if (c1[s[i] - 'a'] < c2[s[i] - 'a']) {
            c1[s[i] - 'a'] += 2;
            if (c1[s[i] - 'a'] >= c2[s[i] - 'a']) cnt++;
        }
        if (c4[s[n - i - 1] - 'a'] < c3[s[n - i - 1] - 'a']) {
            c4[s[n - i - 1] - 'a'] += 2;
            if (c4[s[n - i - 1] - 'a'] >= c3[s[n - i - 1] - 'a']) cnt2++;
        }

        if (cnt == 26 || cnt2 == 26) {
            cout << ans << "\n";
            return;
        }
    }
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