#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mx = 1e6 + 5;

void solve() {
    vector<int> sg(mx);
    for (int i = 1; i * i < mx; i++) {
        vector<int> p;
        for (int j = i - 1; j >= 0; j--) {
            p.push_back(sg[i * j]);
        }
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        sg[i * i] = p.size();
        for (int j = 0; j < p.size(); j++) {
            if (p[j] != j) {
                sg[i * i] = j;
                break;
            }
        }
        p.push_back(sg[i * i]);
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        int res = p.size();
        for (int j = 0; j < p.size(); j++) {
            if (p[j] != j) {
                res = j;
                break;
            }
        }
        for (int j = i * i + 1; j < min(mx, (i + 1) * (i + 1)); j++) {
            sg[j] = res;
        }
    }    

    int ans = 0;
    int n;
    cin >> n;
    for (int i =  0; i < n; i++) {
        int x;
        cin >> x;
        ans ^= sg[x];
    }

    if (ans) cout << "First\n";
    else cout << "Second\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}