#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [&](int x, int y) {
        return a[x] < a[y];
    });

    sort(a.begin(), a.end());
 
    if (unique(a.begin(), a.end()) == a.end()) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << nums[i] + 1 << " \n"[i == n - 1];
        }
    } else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}