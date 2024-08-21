#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    string s;
    cin >> s;
    map<char, int> mp{{'R', 0}, {'G', 1}, {'B', 2}};
    vector<int> cnt(3);
    for (char c : s) {
        cnt[mp[c]]++;
    }

    set<int> st;
    auto cal = [&]() -> void {
        int x = mp[s[0]];
        int y = mp[s[4]];
        if (cnt[x] > cnt[y]) st.insert(x);
        else if (cnt[x] < cnt[y]) st.insert(y);
        else {
            st.insert(x);
            st.insert(y);
        }

    };
    cal();
    // sort(s.begin(), s.end());
    // do {
    // } while (next_permutation(s.begin(), s.end()));

    if (st.size() > 1) {
        cout << "N\n";
    } else {
        int p = *st.begin();
        if (p == 0) cout << "R\n";
        else if (p == 1) cout << "G\n";
        else cout << "B\n";
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