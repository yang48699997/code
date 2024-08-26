#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end(), [](auto &s1, auto &s2) {
        if (s1.length() < s2.length()) {
            if (s1 != s2.substr(0, s1.length())) return s1 > s2;
            else return s1[0] > s2[s1.length()];
        } else if (s1.length() == s2.length()){
            return s1 > s2;
        } else {
            if (s2 != s1.substr(0, s2.length())) return s1 > s2;
            else return s2[0] < s1[s2.length()];
        }
    });
    
    string ans;
    for (int i = 0; i < n; i++) ans += s[i];
    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}