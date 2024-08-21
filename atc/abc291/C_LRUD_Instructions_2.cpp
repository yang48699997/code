#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<pair<int,int>> st;
    st.insert({0, 0});
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            x++;
        } else if (s[i] == 'L') {
            x--;
        } else if (s[i] == 'U') {
            y++;
        } else {
            y--;
        }
        if (st.count({x, y})) {
            cout << "Yes";
            return;
        }
        st.insert({x,y});
    }
    cout << "No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}