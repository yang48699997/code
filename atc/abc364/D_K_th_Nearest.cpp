#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    while (q--) {
        int b, k;
        cin >> b >> k;
        int l = 0, r = 1e9;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            auto it1 = upper_bound(a.begin(), a.end(), b + mid);
            auto it2 = upper_bound(a.begin(), a.end(), b - mid - 1);

            int c = it1 - a.begin();
            c -= it2 - a.begin();
            if (c >= k) r = mid - 1;
            else l = mid + 1;
        }
        cout << l << "\n";

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}