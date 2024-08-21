#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    ll n;
    cin >> n;
    vector<ll> ans;
    ans.push_back(n);
    ll p = n;
    while (true) {
        ll cur = n - (p & -p);
        if (cur == 0 || p == 0LL) break;
        ans.push_back(cur);
        p -= (p & -p);
    }   
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " \n"[i == 0];
    } 
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