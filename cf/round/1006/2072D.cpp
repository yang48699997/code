#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = 0;
    int ans = 1e9;

    int sum = 0;
    vector<vector<int>> cnt(n, vector<int> (n + 1));
    vector<vector<int>> same(n, vector<int> (n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cnt[i][j + 1] = cnt[i][j];
            same[i][j + 1] = same[i][j];
            cnt[i][j + 1] += a[i] > a[j];
            same[i][j + 1] += a[i] == a[j];
        }
        sum += cnt[i][n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int res = sum - 2 * cnt[i][j + 1];
            res += j - i - same[i][j + 1]; 
            if (res < ans) {
                l = i;
                r = j;
                ans = res;
            }
        }
    }

    cout << l + 1 << " " << r + 1 << "\n";
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