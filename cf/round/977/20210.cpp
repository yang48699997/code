#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (--n) {
        sort(a.rbegin(), a.rend());
        int x = a.back();
        a.pop_back();
        int y = a.back();
        a.pop_back();
        a.push_back((x + y) / 2);
    }
    cout << a.back() << "\n";

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