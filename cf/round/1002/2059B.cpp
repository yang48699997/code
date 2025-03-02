#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0;
    int now = 1;
    while (k--) {
        l++;

        if (a[l] != now) {
            cout << now << "\n";
            return;
        }

        int j = l;
        while (j < n && a[j] == a[l]) j++;

        if (j + k - 1 >= n) {
            k--;
            l++;
            now++;
        } else {
            cout << now << "\n";
            return;
        }
        if (k && l + k < n && a[l] != now) {
            cout << now << "\n";
            return;
        } 
    }
    
    cout << now << "\n";
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