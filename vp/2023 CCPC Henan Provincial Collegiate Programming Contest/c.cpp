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
    string s;
    cin >> s;
    ex_KMP<string> kmp(s, s);
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (kmp.get(i) >= 1e3) ans++;
    }

    if (ans < 100) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}