#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    if (n & 1) {
        cout << "No\n";
        return;
    }

    set<char> st;
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1]) {
            cout << "No\n";
            return;
        }
        if (st.count(s[i])) {
            cout << "No\n";
            return;
        }
        st.insert(s[i]);
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}