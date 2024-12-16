#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    
    string s1, s2;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '@') {
            int n = s.size();
            if (i == n - 1) break;
            s1 = s.substr(0, i);
            s2 = s.substr(i + 1, n - i - 1);
        }
    }
    if (s1 == "" || s2 == "") {
        cout << "No\n";
        return;
    }

    if (s1.size() == 0 || s1.size() > 64 || s2.size() > 255) {
        cout << "No\n";
        return;
    }

    set<char> st;
    for (int i = 0; i < 10; i++) {
        st.insert('0' + i);
    }
    for (int i = 0; i < 26; i++) {
        st.insert('a' + i);
        st.insert('A' + i);
    }

    for (int i = 0; i < s1.size(); i++) {
        if (!st.count(s1[i])) {
            if (s1[i] != '.' || i == 0 || s1[i] == s1.back()) {
                cout << "No\n";
                return;
            }
        }
    }

    for (int i = 0; i < s2.size(); i++) {
        if (!st.count(s2[i])) {
            if ((s2[i] != '.' && s2[i] != '-') || i == 0 || s2[i] == s2.back()) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
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