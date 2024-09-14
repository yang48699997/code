#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> p(26);
    for (int i = 0; i < s.length(); i++) {
        p[s[i] - 'a'].push_back(i);
    }
    int l = 0, r = s.length();
    int m = t.length();
    vector<int> time(s.length());
    for (int i = 0; i < s.length(); i++) {
        int x;
        cin >> x;
        time[x - 1] = i + 1;
    }
    while (l <= r) {
        int mid = (l + r) / 2;
        int now = 0;
        int cl = 0;
        while (now < m && cl < s.length()) {
            int c = t[now] - 'a';
            auto it = lower_bound(p[c].begin(), p[c].end(), cl);
            while (it != p[c].end() && time[*it] <= mid) it++;
            if (it == p[c].end()) break;
            cl = *it + 1;
            now++;
        } 
        if (now == m) l = mid + 1;
        else r = mid - 1;
    }
    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}