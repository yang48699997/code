#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    if (s == "Spock") cout << "Pertenece a Star Trek.\n";
    else if (s == "Yoda") cout << "Pertenece a Star Wars.\n";
    else cout << "No pertenece ni a Star Wars ni a Star Trek.\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}