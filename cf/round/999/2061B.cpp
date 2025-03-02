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

    int p = -1;
    map<int, int> v;

    for (int i = 0; i < n; i++) {
        int cnt = ++v[a[i]];
        if (cnt == 2) {
            if (p == -1) p = a[i];
            else {
                cout << p << " " << p << " " << a[i] << " " << a[i] << "\n";
                return;
            }
            v.erase(a[i]);
        }
    }

    if (p == -1) {
        cout << "-1\n";
        return;
    }

    int cnt = 2;
    vector<int> b;

    for (int i = 0; i < n; i++) {
        if (a[i] == p && cnt) {
            cnt--;
        } else b.push_back(a[i]);
    }

    sort(b.begin(), b.end());
    for (int i = 0; i < n - 3; i++) {
        if (b[i] + 2 * p > b[i + 1]) {
            cout << p << " " << p << " " << b[i] << " " << b[i + 1] << "\n";
            return;
        }
    }

    cout << "-1\n";
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