#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    
    map<char, int> mp{{'(', 0}, {')', 0}, {'[', 1}, {']', 1}};

    int n = s.size();
    vector<int> val(n + 1);
    vector<int> p(1, 2);
    int ok = 1;
    int l = 0;
    for (int i = 0; i < n; i++) {
        int now = mp[s[i]];
        if (1 << now & val[l]) {
            ok = 0;
            break;
        }
        if (p.back() == now) {
            val[l] = 0;
            l--;
            p.pop_back();
            val[l] |= 1 << now;
        } else {
            p.push_back(now);
            l++;
        }
    }

    if (ok) cout << "Yes\n";
    else cout << "No\n";
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