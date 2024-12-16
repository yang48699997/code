#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string to(int n) {
    string p;
    while (n) {
        p += '0' + n % 2;
        n /= 2;
    }
    reverse(p.begin(), p.end());
    return p;
}

bool comp(string p, string d) {
    if (p.size() > d.size() || (p.size() == d.size() && p >= d)) return true;
    return false;
}

string add(string s1, string s2) {
    string res;
    int ok = 0;
    if (s1.size() < s2.size()) swap(s1, s2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for (int i = 0; i < s1.size(); i++) {
        int now = ok + s1[i] - '0';
        if (i < s2.size()) now += s2[i] - '0';
        if (now & 1) {
            res += '1';
        } else {
            res += '0';
        }
        ok = now / 2;
    }
    if (ok) res += '1';
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    string s, d, m;
    cin >> s >> d >> m;

    string p = to(s.size());
    
    if (p.size() > d.size() || (p.size() == d.size() && p >= d)) {
        if (comp(to(m.size()), d)) {
            cout << "Infinite money!\n";
            return;
        } else {
            cout << to(m.size()) << "\n";
            return;
        }
    }

    string ans = "0";
    string now = "0";
    while (m.size()) {
        m.pop_back();
        ans = add(ans, "1");
        now = add(now, "1");
        if (now == d) {
            m = add(m, s);
            now = "0";
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}