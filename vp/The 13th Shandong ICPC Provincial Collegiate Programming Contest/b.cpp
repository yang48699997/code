#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int g;
    cin >> g;
    vector<ll> cnt(g);
    map<int, int> mp;
    vector<int> v(g);
    for (int i = 0; i < g; i++) {
        int s, t;
        cin >> s >> t;
        mp[s] = i;
        cnt[i] = t;
    }

    int n;
    cin >> n;
    vector<int> need(n), ok(n);
    vector<vector<pair<int, int>>> add(n);
    vector<vector<pair<int, int>>> pend(g); 
    for (int i = 0; i < n; i++) {
        cin >> need[i];
        for (int j = 0; j < need[i]; j++) {
            int s, num;
            cin >> s >> num;
            if (!mp.count(s)) {
                mp[s] = g++;
                cnt.push_back(0);
                v.push_back(0);
                pend.push_back({}); 
            }
            s = mp[s];
            pend[s].emplace_back(num, i);
        }
        int m;
        cin >> m;
        while (m--) {
            int s, num;
            cin >> s >> num;
            if (!mp.count(s)) {
                mp[s] = g++;
                cnt.push_back(0);
                v.push_back(0);
                pend.push_back({}); 
            }
            s = mp[s];
            add[i].emplace_back(s, num);
        }
    }

    queue<int> q;
    vector<int> now(g);
    for (int i = 0; i < g; i++) {
        q.push(i);
        sort(pend[i].begin(), pend[i].end());
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (need[i] == 0) {
            ans++;
            for (auto [s, ADD] : add[i]) {
                cnt[s] += ADD;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (v[x]) continue;
        int &i = now[x];
        while (i < pend[x].size()) {
            auto [num, index] = pend[x][i];
            if (cnt[x] >= num) {
                ok[index]++;
                i++;
                if (ok[index] == need[index]) {
                    ans++;
                    for (auto [s, ADD] : add[index]) {
                        q.push(s);
                        v[s] = 0;
                        cnt[s] += ADD;
                    }
                }
            } else break;
        }
        v[x] = 1;
    }

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}