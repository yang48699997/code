#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> in(10, vector<int> (10));
vector<vector<int>> out(10, vector<int> (10));
vector<vector<int>> p{
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};
const int mx = 1001;
vector<vector<int>> tin(mx, vector<int> (mx));
vector<vector<int>> tout(mx, vector<int> (mx));

void init() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            in[i][j] = out[i][j] = 0;
            for (int k = 0; k < 7; k++) {
                if (p[i][k] == p[j][k]) continue;
                else if (p[i][k]) {
                    out[i][j]++;
                } else {
                    in[i][j]++;
                }
            }
        }
    } 
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < mx; j++) {
            tin[i][j] = tout[i][j] = 0;
            int n1 = i;
            int n2 = j;
            int t = 3;
            while (t--) {
                tin[i][j] += in[n1 % 10][n2 % 10];
                tout[i][j] += out[n1 % 10][n2 % 10];
                n1 /= 10;
                n2 /= 10;
            }
        }
    }
}

void solve() {
    string s;
    int k;
    cin >> s >> k;

    int ok = 0;
    int n = s.size();
    vector<int> a, b, c;
    int op;
    int l = 0;
    int cnt = 0;
    
    int v1 = 0, v2 = 0, v3 = 0;;
    while (l < n && (s[l] >= '0' && s[l] <= '9')) {
        a.push_back(s[l] - '0');
        l++;
        v1 = v1 * 10 + a.back();
    }
    if (s[l++] == '+') op = 1;
    else op = -1;
    while (l < n && (s[l] >= '0' && s[l] <= '9')) {
        b.push_back(s[l] - '0');
        l++;
        v2 = v2 * 10 + b.back();
    }
    l++;
    while (l < n && (s[l] >= '0' && s[l] <= '9')) {
        c.push_back(s[l] - '0');
        l++;
        v3 = v3 * 10 + c.back();
    }
    
    
    int m1 = a.size();
    int m2 = b.size();
    int m3 = c.size();
    int l1 = pow(10, m1 - 1), r1 = pow(10, m1);
    if (l1 == 1) l1--;
    int l2 = pow(10, m2 - 1), r2 = pow(10, m2);
    if (l2 == 1) l2--;
    int l3 = pow(10, m3 - 1), r3 = pow(10, m3);
    if (l3 == 1) l3--;
    for (int i = l1; i < r1 && !ok; i++) {
        if (tin[v1][i] > k || tout[v1][i] > k) continue;
        for (int j = l2; j < r2; j++) {
            int c1 = tin[v1][i] + tin[v2][j];
            int c2 = tout[v1][i] + tout[v2][j];
            if (tin[v1][i] + tin[v2][j] > k || tout[v1][i] + tout[v2][j] > k) continue;
            if (op == 1) {
                int res = i + j;
                if (to_string(res).size() == m3) {
                    if (c1 + tin[v3][res] == c2 + tout[v3][res] && c1 + tin[v3][res] <= k) ok = 1;
                }
                res = i - j;
                if (res >= 0 && to_string(res).size() == m3) {
                    if (c1 + tin[v3][res] == c2 + tout[v3][res] + 1 && c1 + tin[v3][res] <= k) ok = 1;
                }
            } else {
                int res = i - j;
                if (res >= 0 && to_string(res).size() == m3) {
                    if (c1 + tin[v3][res] == c2 + tout[v3][res] && c1 + tin[v3][res] <= k) ok = 1;
                }
                res = i + j;
                if (to_string(res).size() == m3) {
                    if (c1 + tin[v3][res] + 1 == c2 + tout[v3][res] && c1 + tin[v3][res] <= k - 1) ok = 1;
                }
            }
        }
    }

    if (ok) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    init();
    while (T--) {
        solve();
    }
    return 0;
}