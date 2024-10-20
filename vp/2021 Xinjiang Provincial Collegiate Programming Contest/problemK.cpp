#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p1, p2, l;
    cin >> p1 >> p2 >> l;
    p1--;
    p2--;
    string ans1 = s;
    for (int i = p2; i < p2 + l; i++) {
        ans1[i] = ans1[i - (p2 - p1)];
    }
    cout << ans1 << "\n";
    string ans2 = s;
    for (int i = p2 + l - 1; i >= p2; i--) {
        cerr << i << "\n";
        ans2[i] = s[i - (p2 - p1)];
    }
    cout << ans2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}