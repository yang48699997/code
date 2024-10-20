#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> A[i] >> x;
        p[i] = A[i];
        A[i] += k * x; 
    }
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [&](int x1, int x2) {
        return p[x1] < p[x2];
    });
    sort(A.begin(), A.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[nums[i]] = A[i];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}