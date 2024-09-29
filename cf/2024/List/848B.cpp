#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> g(n), s(n), t(n);
    vector<int> nums(n);
    vector<pair<int, int>> ans(n);
    iota(nums.begin(), nums.end(), 0);
    map<int, vector<int>> mp1, mp2;

    for (int i = 0; i < n; i++) {
        cin >> g[i] >> s[i] >> t[i];
        if (g[i] == 1) mp1[s[i] - t[i]].push_back(s[i]);
        else mp2[s[i] - t[i]].push_back(s[i]);
    }
    for (auto &it : mp1) {
        sort(it.second.begin(), it.second.end());
    }
    for (auto &it : mp2) {
        sort(it.second.begin(), it.second.end());
    }
    
    for (int i = 0; i < n; i++) {
        int p = s[i] - t[i];
        if (g[i] == 1) {
            int s1 = mp1[p].end() - upper_bound(mp1[p].begin(), mp1[p].end(), s[i]);
            int s2 = mp2[p].size();
            if (s2 > s1) {
                ans[i] = make_pair(w, mp2[p][s1]);
            } else {
                ans[i] = make_pair(*(lower_bound(mp1[p].begin(), mp1[p].end(), s[i]) + s2), h);
            }
        } else {
            int s1 = mp1[p].size();
            int s2 = mp2[p].end() - upper_bound(mp2[p].begin(), mp2[p].end(), s[i]);
            if (s1 > s2) {
                ans[i] = make_pair(mp1[p][s2], h);
            } else {
                ans[i] = make_pair(w, *(lower_bound(mp2[p].begin(), mp2[p].end(), s[i]) + s1));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}