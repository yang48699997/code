#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> f(20);
    f[0] = f[1] = 1;
    set<pair<int, int>> st;

    for (int i = 2; i < 20; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    for (int i = 1; i < 19; i++) {
        st.insert({f[i], f[i + 1]});
        st.insert({f[i + 1], f[i]});
    }
    
    vector<vector<int>> g(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    string s;
    cin >> s;
    for (char c : s) {
        vector<vector<int>> tmp(n, vector<int> (n));
        if (c == 'R') {
            for (int i = 0; i < n; i++) {
                for (int j = n - 1; j >= 0; ) {
                    stack<int> stk;
                    int l = j;
                    int lef = 0;
                    while (l >= 0 && g[i][l] != -1) {
                        if (g[i][l] == 0) {
                            l--;
                            continue;
                        }
                        int now = g[i][l];
                        int ok = 0;
                        while (lef && !ok && st.count({stk.top(), now})) {
                            now += stk.top();
                            stk.pop();
                            ok = 1;
                        }
                        stk.push(now);
                        lef = 1 - ok; 
                        l--;
                    }
                    if (l >= 0) tmp[i][l] = -1;
                    int m = stk.size();
                    while (m--) {
                        tmp[i][j - m] = stk.top();
                        stk.pop();
                    }
                    j = l - 1;
                }
            }
        } else if (c == 'L') {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; ) {
                    stack<int> stk;
                    int l = j;
                    int lef = 0;
                    while (l < n && g[i][l] != -1) {
                        if (g[i][l] == 0) {
                            l++;
                            continue;
                        }
                        int now = g[i][l];
                        int ok = 0;
                        while (lef && !ok && st.count({stk.top(), now})) {
                            now += stk.top();
                            stk.pop();
                            ok = 1;
                        }
                        stk.push(now);
                        lef = 1 - ok; 
                        l++;
                    }
                    if (l < n) tmp[i][l] = -1;
                    int m = stk.size();
                    while (m--) {
                        tmp[i][j + m] = stk.top();
                        stk.pop();
                    }
                    j = l + 1;
                }
            }
        } else if (c == 'U') {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; ) {
                    stack<int> stk;
                    int l = j;
                    int lef = 0;
                    while (l < n && g[l][i] != -1) {
                        if (g[l][i] == 0) {
                            l++;
                            continue;
                        }
                        int now = g[l][i];
                        int ok = 0;
                        while (lef && !ok && st.count({stk.top(), now})) {
                            now += stk.top();
                            stk.pop();
                            ok = 1;
                        }
                        stk.push(now);
                        lef = 1 - ok; 
                        l++;
                    }
                    if (l < n) tmp[l][i] = -1;
                    int m = stk.size();
                    while (m--) {
                        tmp[j + m][i] = stk.top();
                        stk.pop();
                    }
                    j = l + 1;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = n - 1; j >= 0; ) {
                    stack<int> stk;
                    int l = j;
                    int lef = 0;
                    while (l >= 0 && g[l][i] != -1) {
                        if (g[l][i] == 0) {
                            l--;
                            continue;
                        }
                        int now = g[l][i];
                        int ok = 0;
                        while (lef && !ok && st.count({stk.top(), now})) {
                            now += stk.top();
                            stk.pop();
                            ok = 1;
                        }
                        stk.push(now);
                        lef = 1 - ok; 
                        l--;
                    }
                    if (l >= 0) tmp[l][i] = -1;
                    int m = stk.size();
                    while (m--) {
                        tmp[j - m][i] = stk.top();
                        stk.pop();
                    }
                    j = l - 1;
                }
            }
        }
        g = tmp;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}