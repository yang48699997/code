#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> p;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        p.emplace_back(l, r);
    }
    sort(p.begin(), p.end(), [&](auto &p1,auto &p2){
        return p1.first < p2.first;
    }); 
    vector<int> ans(2), sum(2);
    sum[1] = 1e9;
    sum[0] = -1;
    int l = 1;
    int res = 0;
    int now = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    while (l <= n - d + 1) {
        while (now < k && p[now].first < l + d) {
            q.push(p[now++].second);
            res++;
        }
        while (!q.empty() && q.top() == l - 1) {
            q.pop();
            res--;
        }
        if (res > sum[0]) {
            ans[0] = l;
            sum[0] = res;
        }
        if (res < sum[1]) {
            ans[1] = l;
            sum[1] = res;
        }
        l++;
    }
    cout << ans[0] << " " << ans[1] << "\n";
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