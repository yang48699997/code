#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n = 5;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    vector<int> p(1 << n);
    vector<string> ans(1 << n);

    for (int i = 0; i < 1 << n; i++) {
        ans[i] = "";
        for (int j = 0; j < n; j++) {
            if (1 << j & i) {
                ans[i] += char('A' + j);
                p[i] += d[j];
            }
        }
    }

    vector<int> nums((1 << n) - 1);
    iota(nums.begin(), nums.end(), 1);
    sort(nums.begin(), nums.end(), [&](int x1, int x2) {
        if (p[x1] != p[x2]) return p[x1] > p[x2];
        return ans[x1] < ans[x2];
    });

    for (int i : nums) {
        cout << ans[i] << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}