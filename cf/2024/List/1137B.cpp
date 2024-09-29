#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct ex_KMP{
    T s1, s2;
    vector<int> nxt, ex;
    int n, m;
    ex_KMP(T s1, T s2) : nxt(s2.size()), ex(s1.size()) {
        n = s1.size();
        m = s2.size();
        this -> s1 = s1;
        this -> s2 = s2;
        int a = 0, p = 0;
        nxt[0] = m;
        for(int i = 1; i < m; i++) {
            if (i >= p || i + nxt[i - a] >= p) {
                if (i >= p) p = i;
                while (p < m && s2[p] == s2[p - i]) p++;
                nxt[i] = p - i;
                a = i;
            } else nxt[i] = nxt[i - a];
        }
        a = 0;
        p = 0;
        for (int i = 0; i < n; i++) {
            if (i >= p || i + nxt[i - a] >= p) {
                if (i >= p) p = i;
                while (p < n && p - i < m && s1[p] == s2[p - i]) p++;
                ex[i] = p - i;
                a = i;
            } else ex[i] = nxt[i - a];
        }
    }
    int get(int i) {
        return ex[i];
    }
};


void solve() {
    string s, t;
    cin >> s >> t;
    vector<int> cnt(2);
    for (char c : s) {
        cnt[c - '0']++;
    }
    string ans;
    ex_KMP<string> kmp(t, t);
    for (int i = 0; i < t.size(); i++) {
        if (cnt[t[i] - '0']) {
            ans += t[i];
            cnt[t[i] - '0']--;
        }
        else if (cnt[(t[i] - '0') ^ 1]) {
            ans += (char)(((t[i] - '0') ^ 1) + '0');
            cnt[(t[i] - '0') ^ 1]--;
        }
    }
    int p = t.size();
    for (int i = 1; i < t.size(); i++) {
        if (kmp.get(i) == t.size() - i) {
            p = i;
            break;
        } 
    }
    int i = 0;

    while (ans.size() < s.size()) {
        i += t.size() - p;
        if (cnt[t[i] - '0']) {
            ans += t[i];
            cnt[t[i] - '0']--;
        }
        else if (cnt[(t[i] - '0') ^ 1]) {
            ans += (char)(((t[i] - '0') ^ 1) + '0');
            cnt[(t[i] - '0') ^ 1]--;
        }
        i -= t.size() - p - 1;
        i %= p;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}