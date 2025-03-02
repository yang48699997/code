#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }

    int len = 0;
    int l = 0;
    for (int i = 0; i < n; ) {
        if (cnt[a[i]] > 1) {
            i++;
            continue;
        }

        int j = i;
        while (j < n && cnt[a[j]] == 1) j++;
        if (j - i > len) {
            l = i + 1;
            len = j - i;
        }

        i = j;
    }

    if (len == 0) cout << "0\n";
    else cout << l << " " << l + len - 1 << "\n"; 
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