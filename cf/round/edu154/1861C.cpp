#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> p(n + 10, -1);
    int l = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+') {
            if (p[l] == 0) p[++l] = 0;
            else p[++l] = -1;
        } else if (s[i] == '-') {
            if (p[l] == 1) p[--l] = 1;
            else l--;
        } else if (s[i] == '1') {
            if (p[l] == 0) {
                cout << "NO\n";
                return;
            } 
            p[l] = 1;
        } else if (s[i] == '0') {
            if (p[l] == 1 || l < 2) {
                cout << "NO\n";
                return;
            }
            if (l > 1) p[l] = 0;
        }
    }
    cout << "YES\n";
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