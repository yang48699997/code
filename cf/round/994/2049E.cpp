#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int q(int l, int r) {
    cout << "? " << l << " " << r << endl;

    int res;
    cin >> res;

    return res;
}

void solve() {
    int n;
    cin >> n;

    int a = q(1, n / 2);
    int b = q(n / 4 + 1, n / 4 * 3);

    int ans = -1;
    if (a == 0) {
        int c = q(1, n / 4);
        int d = q(n / 4 + 1, n / 2);
        if (c == d) {
            int l = 1;
            int r = n / 2 + 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (q(mid, n) == 1) {
                    r = mid - 1;
                    ans = n - r + 1;
                } else {
                    l = mid + 1;
                    ans = n - mid + 1;
                }
            }
        } else {
            int l = n / 2 - 1;
            int r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (q(mid, n) == 1) {
                    l = mid + 1;
                    ans = n - mid + 1;
                } else {
                    r = mid - 1;
                    ans = n - r + 1;
                }
            }
        }
    } else {
        int c = q(1, n / 4);
        int d = q(n / 4 + 1, n / 2);
        if (c != d) {
            int l = n / 2 - 1;
            int r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (q(1, mid) == 1) {
                    l = mid + 1;
                    ans = l;
                } else {
                    r = mid - 1;
                    ans = mid;
                }
            }
        } else {
            int l = 1, r = n / 2 + 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (q(1, mid) == 0) {
                    l = mid + 1;
                    ans = l;
                } else {
                    r = mid - 1;
                    ans = mid;
                }
            }
        }
    }

    cout << "! " << ans << endl;
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