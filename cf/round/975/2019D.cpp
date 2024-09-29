#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int cl = 0, cr = n - 1;
    while (cl != cr) {
        if (a[cl] >= a[cr]) cl++;
        else cr--;
    }
    auto check = [&](int k) -> int {
        int p = 1;
        deque<pair<int, int>> q;
        deque<pair<int, int>> q2;
        for (int i = k - 1; i >= 0; i--) {
            int now = a[i] - p;
            if (now <= 0) return 0; 
            while (!q.empty() && q.back().first >= now) {
                q.pop_back();
            }
            q.push_back({now, i});
        }
        p = 1;
        for (int i = k + 1; i < n; i++) {
            int now = a[i] - p;
            if (now <= 0) return 0; 
            while (!q2.empty() && q2.back().first >= now) {
                q2.pop_back();
            }
            q2.push_back({now, i});
        }
        int cnt = 0;
        int p1 = k, p2 = k;
        while (!q.empty() && !q2.empty()) {
            auto [x1, i1] = q.front();
            auto [x2, i2] = q2.front();
            if (x1 <= x2) {
                q.pop_front();
                cnt += p1 - i1;
                if (cnt > x1) return 0;
                p1 = i1; 
            } else {
                q2.pop_front();
                cnt += i2 - p2;
                if (cnt > x2) return 0;
                p2 = i2; 
            }
        }
        while (!q.empty()) {
            auto [x1, i1] = q.front();
            q.pop_front();
            cnt += p1 - i1;
            if (cnt > x1) return 0;
            p1 = i1; 
        }
        while (!q2.empty()) {
            auto [x2, i2] = q2.front();
            q2.pop_front();
            cnt += i2 - p2;
            if (cnt > x2) return 0;
            p2 = i2; 
        }
        return 1;
    };

    int l = cl, r = n - 1;
    while (l <= r) {
        int mid = (r + l) / 2;
        if (!check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    int l2 = 0, r2 = cl;
    while (l2 <= r2) {
        int mid = (l2 + r2) / 2;
        if (check(mid)) r2 = mid - 1;
        else l2 = mid + 1;
    }
    cout << max(r - r2, 0) << "\n";
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