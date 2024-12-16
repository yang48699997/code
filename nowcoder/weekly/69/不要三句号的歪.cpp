#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll to_ll(string s) {
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<string> p;
    for (int i = 0; i < n; ) {
        int j = i;
        string now = "";

        while (j < n && s[j] != ',') {
            now += s[j];
            j++;
        }
        i = j + 1;
        p.push_back(now);
    }

    cout << to_ll(p[3]) - to_ll(p[1]) - 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}