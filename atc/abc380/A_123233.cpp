#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    if (s == "122333") cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}