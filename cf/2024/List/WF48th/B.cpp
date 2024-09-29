#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> last, cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            cnt[x]++;
            last[x] = i;
        }
    }
    vector<double> ans(n);
    double sum = n * k;
    for (auto it = last.begin(); it != last.end(); it++) {
        int x = it -> first;
        int i = it -> second;
        int p = cnt[x];
        ans[i] += p / sum;
    }
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(9) << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}