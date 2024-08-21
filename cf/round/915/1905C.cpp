#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res = s;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        while (p.size() && s[i] > s[p.back()]) p.pop_back();
        p.push_back(i);
    }
    
    int cnt = p.size();
    for (int i = 0; i < p.size(); i++) {
        if (s[p[i]] == s[p[0]]) cnt--;
        else break;
    }
    for (int i = 0; i < p.size(); i++) {
        res[p[i]] = s[p[p.size() - i - 1]];
    }
    sort(s.begin(), s.end());

    if (s == res) cout << cnt << "\n";
    else cout << "-1\n";
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