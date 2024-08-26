#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mx = 1e5 + 5;


void solve() {
    int n;
    cin >> n;
    int ans = 0;    

    vector<int> sg(mx);
    vector<vector<int>> p(mx);
    for (int i = 1; i < mx; i++) {
        sort(p[i].begin(), p[i].end());
        int m = unique(p[i].begin(), p[i].end()) - p[i].begin();
        p[i].resize(m);
        sg[i] = p[i].size();
        for (int j = 0; j < p[i].size(); j++) {
            if (p[i][j] != j) {
                sg[i] = j;
                break;
            }
        }
        for (int j = i + i; j < mx; j += i) {
            p[j].push_back(sg[i]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans ^= sg[x];
    }

    if (ans) cout << "Anna";
    else cout << "Bruno";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}