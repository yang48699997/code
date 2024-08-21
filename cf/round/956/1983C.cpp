#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int T;

vector<pair<int,int>> cal(vector<ll> &a, ll t) {
    int n = a.size();
    vector<pair<int,int>> ans;
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    for (int  i = 0; i < n; i++) {
        auto it = lower_bound(pre.begin(), pre.end(), pre[i] + t);
        if (it == pre.end())continue;
        ans.push_back({i + 1, (it - pre.begin())});
    }
    return ans;
}

vector<pair<int,int>> f(vector<pair<int,int>> &p1, vector<pair<int,int>> &p2, vector<pair<int,int>> &p3) {
    int j = 0, k = 0;
    vector<pair<int,int>> ans;
    for (int i = 0; i < p1.size(); i++) {
        int l1 = p1[i].first;
        int r1 = p1[i].second;
        while (j < p2.size() && p2[j].first <= r1) j++;
        if (j == p2.size()) return ans;
        int l2 = p2[j].first;
        int r2 = p2[j].second;
        while (k < p3.size() && p3[k].first <= r2) k++;
        if (k == p3.size()) return ans;
        int l3 = p3[k].first;
        int r3 = p3[k].second;
        ans.push_back({l1, r1});
        ans.push_back({l2, r2});
        ans.push_back({l3, r3});
        return ans;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    ll tot = 0;
    for (int i = 0; i < n; i++) tot += a[i];
    ll t = tot / 3;
    if (tot % 3) t++;
    vector<vector<pair<int,int>>> p;
    vector<pair<int,int>> p1 = cal(a, t);
    vector<pair<int,int>> p2 = cal(b, t);
    vector<pair<int,int>> p3 = cal(c, t);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == j || i == k || j == k) continue;
                vector<pair<int,int>> res = f(p[i], p[j], p[k]);
                if (res.size()== 0) continue;
                vector<pair<int,int>> ans;
                for (int q = 0; q < 3; q++) {
                    if (i == q) ans.push_back(res[0]);
                    if (j == q) ans.push_back(res[1]);
                    if (k == q) ans.push_back(res[2]);
                }
                if (ans.size()) {
                    for (auto [l, r] : ans) cout << l << " " << r << " ";
                    cout << "\n";
                    return;
                }
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}