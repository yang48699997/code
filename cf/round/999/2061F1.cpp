#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<array<int, 2>> cal(string &s) {
    int n = s.size();
    vector<array<int, 2>> res;
    for (int i = 0; i < n; ) {
        int p = s[i] - '0';
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        res.push_back({p, j - i});
        i = j;
    }
    return res;
}

void solve() {
    string s, t;
    cin >> s >> t;

    if (count(s.begin(), s.end(), '0') != count(t.begin(), t.end(), '0')) {
        cout << "-1\n";
        return;
    }

    vector<array<int, 2>> p1 = cal(s); 
    vector<array<int, 2>> p2 = cal(t); 

    int n = p1.size();
    int m = p2.size();
    int l1 = 0, l2 = 0;

    if (n == 2) {
        if (m > 2) cout << "-1\n";
        else cout << (p1[0][0] != p2[0][0]) << "\n";
        return;
    }

    int ans = 0;

    if (p1[0][0] != p2[0][0]) {
        ans++;
        l1++;
        p1[2][1] += p1[0][1];
    }

    while (l2 < m) {
        while (p1[l1][1] < p2[l2][1]) {
            if (l1 + 3 < n) {
                p1[l1 + 2][1] += p1[l1][1];
                p1[l1 + 3][1] += p1[l1 + 1][1];
                l1 += 2;
            } else {
                int t1 = p1[l1][1];
                int t2 = p1[l1 + 1][1];
                int t3 = p1[l1 + 2][1];
                p1[l1 + 1] = {0, t1 + t3};
                p1[l1 + 2] = {0, t2};
                l1++;
            }
            ans++;
        }

        if (p1[l1][1] != p2[l2][1]) {
            cout << "-1\n";
            return;
        } else {
            l2++;
            l1++;
        }
    }

    cout << ans << "\n";

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