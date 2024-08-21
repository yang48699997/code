#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    string s;
    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        if (isupper(s[i])) {
            cout << i + 1;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}