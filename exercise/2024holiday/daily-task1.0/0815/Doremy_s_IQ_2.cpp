#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int cal(vector<int> a) {
    int n = a.size();
    int l = n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            l = i;
            break;
        }
    }
    int now = 0;
    int cnt0 = 0;
    int cnt1 = 0;
    int r = 0;
    for (int i = l - 1; i >= r;) {
        if (now == a[i]) {
            cnt1++;
            i--;
            continue;
        } else if (now > a[r]) {
            now--;
        }
        r++;
    }
    ans = cnt1;
    int cur = 0;
    int rr = n - 1;
    for (int i = l; i <= rr;) {
        if (a[i] == cur) {
            cnt0++;
            i++;
            ans = max(ans, cnt0 + cnt1);
            continue;
        } else if (a[rr] > cur){
            cur++;
            now++;
            if (r < l && a[r] < now) {
                now--;
                r++;
                cnt1--;
            }
            ans = max(ans, cnt0 + cnt1);
        }
        rr--;
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = n;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            l = i;
            break;
        }
    }

    int ans = cal(a);
    for (int i = 0; i < n; i++) {
        a[i] = -a[i];
    }
    reverse(a.begin(), a.end());
    ans = max(ans, cal(a));
    cout << ans << "\n";
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