#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int p = sqrt(n);
    vector<pair<int, int>> p1, p2;

    if (p * p < n) p++;
    for (int i = 1; i <= n; i++) {
        if (i + p <= n) p1.emplace_back(i, i + p);
        if (i % p) p2.emplace_back(i, i + 1);
    }

    cout << p1.size() << "\n";
    for (int i = 0; i < p1.size(); i++) {
        cout << p1[i].first << " " << p1[i].second << "\n";
    }
    for (int j = 0; j < p1.size(); j++) {
        cout << p2[j].first << " " << p2[j].second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}