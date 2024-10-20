#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), nums(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    iota(nums.begin(), nums.end(), 0);

    sort(nums.begin(), nums.end(), [&](int x1, int x2){
        if (a[x1] != a[x2]) return a[x1] < a[x2];
        return x1 < x2;
    });

    for (int i : nums) cout << i + 1 << " \n"[i == nums.back()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}