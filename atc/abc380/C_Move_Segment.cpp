#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    k--;

    vector<int> l, r;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        l.push_back(i);
        while (i < n && s[i] == '1') i++;
        i--;
        r.push_back(i);
    }

    for (int i = l[k]; i <= r[k]; i++) s[i] = '0';
    for (int i = r[k - 1] + 1; i <= r[k - 1] + r[k] - l[k] + 1; i++) s[i] = '1';

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}