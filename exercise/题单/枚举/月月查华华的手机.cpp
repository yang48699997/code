#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vector<int>> p(26);
    for (int i = 0; i < s.length(); i++) {
        p[s[i] - 'a'].push_back(i);
    }
    while (n--) {
        string s2;
        cin >> s2;
        int l = 0;
        int ok = 1;
        for (char c : s2) {
            auto it = lower_bound(p[c - 'a'].begin(), p[c - 'a'].end(), l);
            if (it == p[c - 'a'].end()) {
                ok = 0;
                break;
            } else l = *it + 1;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}