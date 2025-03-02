#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    set<string> st = {
        "ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"
    };

    string s;
    cin >> s;

    if (st.count(s)) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}