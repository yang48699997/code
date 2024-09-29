#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] > i + 1) {
            cout << -1 << endl;
            return;
        }
        cnt[a[i]].push_back(i);
    }
    vector<int> ans(n);
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        if (cur > n) break;
        int siz = cnt[i].size();
        if (siz == 0 && cur <= n) {
            cout << -1 << endl;
            return;
        }
        for (int j = siz - 1; j >= 0; j--) {
            ans[cnt[i][j]] = cur;
            cur++;
        }
    }
    for (auto i : ans) {
        cout << i << " ";
    }
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}