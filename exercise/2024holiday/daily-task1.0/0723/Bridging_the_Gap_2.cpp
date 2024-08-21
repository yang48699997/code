#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i];
    if (n == r) {
        cout << "Yes\n";
        return;
    }
    if (l == r) {
        cout << "No\n";
        return;
    }
    sort(a.begin(), a.end());
    map<ll, int> mp1, mp2, mp3;
    for (int i = n - l; i < n; i++) mp1[a[i]]++;
    for (int i = 0; i < n - l; i++) mp2[a[i]]++;
    int d = 0;
    int cnt = (n - r - 1) / (r - l) + 1;
    int cur = 0;
    int left = n - r;
    while (cur++ < cnt) {
        ll p1 = mp1.begin()->first;
        ll p2 = mp2.rbegin()->first;
        int c1 = mp1.begin()->second;
        int c2 = mp2.rbegin()->second;
        while (p1 - d < p2) {
            if (c1 <= c2) {
                mp1[p2 + d] += c2;
                mp2[p2] -= c2;
                if (mp2[p2] == 0) mp2.erase(mp2.find(p2));
                mp2[p1 - d] += c2;
                mp1.erase(mp1.find(p1));
                break;
            } else {
                mp1[p1] -= c2;
                mp1[p2 + d] += c2;
                mp2.erase(p2);
                mp2[p1 - d] += c2;
                p2 = mp2.rbegin()->first;
                p1 = mp1.begin()->first;
                c1 = mp1.begin()->second;
                c2 = mp2.rbegin()->second;
            }
        }
        if (mp1.begin()->first <= d) {
            cout << "No\n";
            return;
        }
        d++;
        int c = 0;
        int cp = r - l;
        while (!mp2.empty() && c < cp) {
            int cc = mp2.begin() -> second;
            int pp = min(r - l - c, cc);
            mp2.begin()->second -= pp;
            ll now = mp2.begin()->first;
            if (now > 1) {
                mp3[now - 1] += pp;
            }
            if (mp2.begin()->second == 0) mp2.erase(mp2.begin());
            c += pp;
        }
        while (!mp3.empty() && mp3.rbegin() -> first > mp1.begin()->first - d) {
            p1 = mp1.begin()->first;
            p2 = mp3.rbegin()->first;
            c1 = mp1.begin()->second;
            c2 = mp3.rbegin()->second;
            if (c1 <= c2) {
                mp1[p2 + d] += c2;
                mp3[p2] -= c2;
                if (mp3[p2] == 0) mp3.erase(mp3.find(p2));
                mp3[p1 - d] += c2;
                mp1.erase(mp1.find(p1));
                break;
            } else {
                mp1[p1] -= c2;
                mp1[p2 + d] += c2;
                mp3.erase(p2);
                mp3[p1 - d] += c2;
                p2 = mp3.rbegin()->first;
                p1 = mp1.begin()->first;
                c1 = mp1.begin()->second;
                c2 = mp3.rbegin()->second;
            }
        }   
        if (mp1.begin()->first <= d) {
            cout << "No\n";
            return;
        }
        d++;
    }
    if (mp1.begin()->first <= d && (mp2.empty() || mp2.begin()->first > 0)) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}