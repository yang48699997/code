#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    vector<string> p;
    p.push_back(s);
    int n = s.size();
    for (int i = 1; i < s.size(); i++) {
        p.push_back(s.substr(i, n - i) + s.substr(0, i));
    }

    sort(p.begin(), p.end());
    cout << p[0] << "\n";
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