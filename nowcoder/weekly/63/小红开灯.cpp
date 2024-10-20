#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string x_or(string s1, string &s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[i]) s1[i] = '0';
        else s1[i] = '1';
    }
    return s1;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<array<int, 2>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    vector<string> val(n);
    for (int i = 0; i < n; i++) {
        val[i] = string(n, '0');
        for (int j = 0; j < n; j++) {
            if (p[i][0] == p[j][0] || p[i][1] == p[j][1]) {
                val[i][j] = '1';
            }
        }
    }

    vector<set<int>> st(n);

    bool zero = false;
    vector<string> nums(n, string(n, '0'));

    auto insert = [&](string s, int k) -> void {
        set<int> p;
        p.insert(k);
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') continue;
            if (nums[i][i] == '0') {
                nums[i] = s;
                st[i] = p;
                return;
            } else {
                s = x_or(s, nums[i]);
                for (int x : st[i]) {
                    if (p.count(x)) p.erase(x);
                    else p.insert(x);
                }
            }
        }
    };

    for (int i = 0; i < n; i++) {
        insert(val[i], i);
    }

    set<int> pp;
    string tmp = string(n, '1');
    s = x_or(s, tmp);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') continue;
        if (nums[i][i] == '0') {
            cout << "-1\n";
            return;
        } else {
            s = x_or(s, nums[i]);
            for (int x : st[i]) {
                if (pp.count(x)) pp.erase(x);
                else pp.insert(x);
            }
        }
    }

    cout << pp.size() << "\n";
    int cnt = 0;
    for (auto it = pp.begin(); it != pp.end(); it++) {
        cnt++;
        cout << (*it + 1) << " \n"[cnt == pp.size()];
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}