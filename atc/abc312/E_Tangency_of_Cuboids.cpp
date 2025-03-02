#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 101;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 4>> p(n);
    vector<vector<vector<int>>> f1(N, vector<vector<int>> (N, vector<int> (N, -1)));
    vector<vector<vector<int>>> f2(N, vector<vector<int>> (N, vector<int> (N, -1)));
    vector<vector<vector<int>>> d1(N, vector<vector<int>> (N, vector<int> (N, -1)));
    vector<vector<vector<int>>> d2(N, vector<vector<int>> (N, vector<int> (N, -1)));
    vector<vector<vector<int>>> l1(N, vector<vector<int>> (N, vector<int> (N, -1)));
    vector<vector<vector<int>>> l2(N, vector<vector<int>> (N, vector<int> (N, -1)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> p[i][j];
        }
        for (int x = p[i][0]; x < p[i][3]; x++) {
            for (int y = p[i][2]; y < p[i][5]; y++) {
                f1[p[i][1]][x][y] = i;
            }
        }
        for (int x = p[i][0]; x < p[i][3]; x++) {
            for (int y = p[i][2]; y < p[i][5]; y++) {
                f2[p[i][4]][x][y] = i;
            }
        }
        for (int x = p[i][0]; x < p[i][3]; x++) {
            for (int y = p[i][1]; y < p[i][4]; y++) {
                d1[p[i][2]][x][y] = i;
            }
        }
        for (int x = p[i][0]; x < p[i][3]; x++) {
            for (int y = p[i][1]; y < p[i][4]; y++) {
                d2[p[i][5]][x][y] = i;
            }
        }
        for (int x = p[i][1]; x < p[i][4]; x++) {
            for (int y = p[i][2]; y < p[i][5]; y++) {
                l1[p[i][0]][x][y] = i;
            }
        }
        for (int x = p[i][1]; x < p[i][4]; x++) {
            for (int y = p[i][2]; y < p[i][5]; y++) {
                l2[p[i][3]][x][y] = i;
            }
        }
    }

    vector<int> ans(n);
    set<pair<int, int>> st;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (f1[i][j][k] != -1 && f2[i][j][k] != -1) {
                    int a = f1[i][j][k], b = f2[i][j][k];
                    if (a > b) swap(a, b);
                    if (!st.count({a, b})) {
                        ans[a]++;
                        ans[b]++;
                        st.insert({a, b});
                    }
                }
                if (d1[i][j][k] != -1 && d2[i][j][k] != -1) {
                    int a = d1[i][j][k], b = d2[i][j][k];
                    if (a > b) swap(a, b);
                    if (!st.count({a, b})) {
                        ans[a]++;
                        ans[b]++;
                        st.insert({a, b});
                    }
                }
                if (l1[i][j][k] != -1 && l2[i][j][k] != -1) {
                    int a = l1[i][j][k], b = l2[i][j][k];
                    if (a > b) swap(a, b);
                    if (!st.count({a, b})) {
                        ans[a]++;
                        ans[b]++;
                        st.insert({a, b});
                    }
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}