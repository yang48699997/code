#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

struct ex_KMP{
    vector<int> s1, s2;
    vector<int> nxt, ex;
    int n, m;
    ex_KMP(vector<int> s1, vector<int> s2) : nxt(s2.size()), ex(s1.size()) {
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
    int n, w;
    cin >> n >> w;
    if (w == 1) {
        cout << n << "\n";
        return;
    }
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    vector<int> a(n - 1);
    int pre;
    cin >> pre;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        a[i - 1] = x - pre;
        pre = x;
    }
    vector<int> b(w - 1);
    cin >> pre;
    for (int i = 1; i < w; i++) {
        int x;
        cin >> x;
        b[i - 1] = x - pre;
        pre = x;
    }
    ex_KMP ex(a, b);
    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
        if (ex.get(i) >= w - 1) ans++;
    }

    cout << ans << "\n";
        
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}