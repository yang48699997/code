#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int k;
    vector<int> n(3);
    vector<int> t(3);
    cin >> k;
    for (int i = 0; i < 3; i++) cin >> n[i];
    for (int i = 0; i < 3; i++) cin >> t[i];
    deque<int> q1, q2, q3;
    for (int i = 0; i < t[0]; i++) q1.push_back(0);
    for (int i = 0; i < t[1]; i++) q2.push_back(0);
    for (int i = 0; i < t[2]; i++) q3.push_back(0);
    int cnt1 = n[0], cnt2 = n[1], cnt3 = n[2];
    int l = 1;
    while (k) {
        cnt1 += q1.front();
        cnt2 += q2.front();
        cnt3 += q3.front();
        q1.pop_front();
        q2.pop_front();
        q3.pop_front();
        int p = min({cnt1, cnt2, cnt3});
        k -= min(p, k);
        cnt1 -= p;
        cnt2 -= p;
        cnt3 -= p;
        q1.push_back(p);
        q2.push_back(p);
        q3.push_back(p);
        l++;
    }
    cout << l + t[0] + t[1] + t[2] - 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}