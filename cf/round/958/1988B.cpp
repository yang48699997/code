#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' ) cnt1++;
        else {
            int j = i;
            while (j < n && s[j] == '0') {
                j++;
            }
            cnt2++;
            i = j - 1;
        }
    }
    if (cnt1 > cnt2) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}