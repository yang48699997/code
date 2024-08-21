#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n = 9, m = 12;
    vector<string> s(n);
    for (int i = 0; i < n ; i++) {
        cin >> s[i];
    }

    vector<vector<int>> ans;
    int dy[6] = {3, 0, 3, 6, 9, 3}; 
    int dx[6] = {0, 3, 3, 3, 3, 6}; 
    int cor[8][3][2] = {{{3, 2}, {3, 3}, {2, 3}},
                        {{3, 5}, {2, 5}, {3, 6}},
                        {{5, 2}, {5, 3}, {6, 3}},
                        {{5, 5}, {6, 5}, {5, 6}},
                        {{3, 0}, {0, 3}, {3, 11}},
                        {{5, 0}, {8, 3}, {5, 11}},
                        {{8, 5}, {5, 8}, {5, 9}},
                        {{0, 5}, {3, 8}, {3, 9}}
                        };
    auto check = [&](vector<string> &p) -> bool {
        for (int i = 0; i < 6; i++) {
            int x = dx[i];
            int y = dy[i];
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (p[x + j][y + k] != p[x][y]) return false;
                }
            }
        }
        return true;
    };

    auto dfs = [&](auto &&self, int o, vector<string> p) -> int {
        if (check(p)) return true;
        vector<string> cur = p;
        if (o > 3) {
            return false;
        } else if (o == 3) {
            if (ans.size() == 0){
                for (int i = 0; i < 8; i++) {
                    int x1 = cor[i][0][0], y1 = cor[i][0][1];
                    int x2 = cor[i][1][0], y2 = cor[i][1][1];
                    int x3 = cor[i][2][0], y3 = cor[i][2][1];
                    
                    int ok = 0;

                    cur[x1][y1] = p[x2][y2]; 
                    cur[x2][y2] = p[x1][y1];
                    ok |= check(cur);
                    cur[x1][y1] = p[x1][y1]; 
                    cur[x2][y2] = p[x2][y2];

                    cur[x1][y1] = p[x3][y3]; 
                    cur[x3][y3] = p[x1][y1];
                    ok |= check(cur);
                    cur[x1][y1] = p[x1][y1]; 
                    cur[x3][y3] = p[x3][y3];

                    cur[x3][y3] = p[x2][y2]; 
                    cur[x2][y2] = p[x3][y3];
                    ok |= check(cur);
                    if (ok) {
                        ans.push_back({p[x1][y1] - '0', p[x2][y2] - '0', p[x3][y3] - '0'});
                    }
                }
            }
            return false;
        }

        int x = 0, y = 0;



        // 3 L
        for(int i = 0; i < 12; i++) {
            cur[3][i] = p[3][(i + 3) % 12];
        }
        x = 0, y = 3;
        cur[x][y] = p[x + 2][y];
        cur[x + 1][y] = p[x + 2][y + 1];
        cur[x + 1][y + 2] = p[x][y + 1];
        cur[x + 2][y] = p[x + 2][y + 2];
        cur[x + 2][y + 1] = p[x + 1][y + 2];
        cur[x + 2][y + 2] = p[x][y + 2];
        cur[x][y + 1] = p[x + 1][y];
        cur[x][y + 2] = p[x][y];
        if (self(self, o + 1, cur)) return true;
        for(int i = 0; i < 12; i++) {
            cur[3][i] = p[3][i];
        }
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];
        // 5 L
        for(int i = 0; i < 12; i++) {
            cur[5][i] = p[5][(i + 3) % 12];
        }
        x = 6, y = 3;
        cur[x][y] = p[x][y + 2];
        cur[x + 1][y] = p[x][y + 1];
        cur[x + 1][y + 2] = p[x + 2][y + 1];
        cur[x + 2][y] = p[x][y];
        cur[x + 2][y + 1] = p[x + 1][y];
        cur[x + 2][y + 2] = p[x + 2][y];
        cur[x][y + 1] = p[x + 1][y + 2];
        cur[x][y + 2] = p[x + 2][y + 2];
        if (self(self, o + 1, cur)) return true;
        for(int i = 0; i < 12; i++) {
            cur[5][i] = p[5][i];
        }
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];
        // 3 R
        for(int i = 0; i < 12; i++) {
            cur[3][i] = p[3][(i + 9) % 12];
        }
        x = 0, y = 3;
        cur[x][y] = p[x][y + 2];
        cur[x + 1][y] = p[x][y + 1];
        cur[x + 1][y + 2] = p[x + 2][y + 1];
        cur[x + 2][y] = p[x][y];
        cur[x + 2][y + 1] = p[x + 1][y];
        cur[x + 2][y + 2] = p[x + 2][y];
        cur[x][y + 1] = p[x + 1][y + 2];
        cur[x][y + 2] = p[x + 2][y + 2];
        if (self(self, o + 1, cur)) return true;
        for(int i = 0; i < 12; i++) {
            cur[3][i] = p[3][i];
        }
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];
        // 5 R
        x = 6, y = 3;
        cur[x][y] = p[x + 2][y];
        cur[x + 1][y] = p[x + 2][y + 1];
        cur[x + 1][y + 2] = p[x][y + 1];
        cur[x + 2][y] = p[x + 2][y + 2];
        cur[x + 2][y + 1] = p[x + 1][y + 2];
        cur[x + 2][y + 2] = p[x][y + 2];
        cur[x][y + 1] = p[x + 1][y];
        cur[x][y + 2] = p[x][y];
        for(int i = 0; i < 12; i++) {
            cur[5][i] = p[5][(i + 9) % 12];
        }
        if (self(self, o + 1, cur)) return true;
        for(int i = 0; i < 12; i++) {
            cur[5][i] = p[5][i];
        }
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];
        // 3 U
        for (int i = 0; i < 3; i++) cur[i][3] = p[5 - i][11];
        for (int i = 3; i < 9; i++) cur[i][3] = p[i - 3][3];
        for (int i = 0; i < 3; i++) cur[3 + i][11] = p[8 - i][3];
        x = 3, y = 0;
        cur[x][y] = p[x + 2][y];
        cur[x + 1][y] = p[x + 2][y + 1];
        cur[x + 1][y + 2] = p[x][y + 1];
        cur[x + 2][y] = p[x + 2][y + 2];
        cur[x + 2][y + 1] = p[x + 1][y + 2];
        cur[x + 2][y + 2] = p[x][y + 2];
        cur[x][y + 1] = p[x + 1][y];
        cur[x][y + 2] = p[x][y];
        if (self(self, o + 1, cur)) return true;
        for (int i = 0; i < 3; i++) cur[i][3] = p[i][3];
        for (int i = 3; i < 9; i++) cur[i][3] = p[i][3];
        for (int i = 0; i < 3; i++) cur[3 + i][11] = p[3 + i][11];
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];
        // 3 D
        for (int i = 0; i < 6; i++) cur[i][3] = p[i + 3][3];
        for (int i = 6; i < 9; i++) cur[i][3] = p[11 - i][11];
        for (int i = 0; i < 3; i++) cur[3 + i][11] = p[2 - i][3];
        x = 3, y = 0;
        cur[x][y] = p[x][y + 2];
        cur[x + 1][y] = p[x][y + 1];
        cur[x + 1][y + 2] = p[x + 2][y + 1];
        cur[x + 2][y] = p[x][y];
        cur[x + 2][y + 1] = p[x + 1][y];
        cur[x + 2][y + 2] = p[x + 2][y];
        cur[x][y + 1] = p[x + 1][y + 2];
        cur[x][y + 2] = p[x + 2][y + 2];
        if (self(self, o + 1, cur)) return true;
        for (int i = 0; i < 3; i++) cur[i][3] = p[i][3];
        for (int i = 3; i < 9; i++) cur[i][3] = p[i][3];
        for (int i = 0; i < 3; i++) cur[3 + i][11] = p[3 + i][11];
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];
        // 5 U
        for (int i = 0; i < 3; i++) cur[i][5] = p[5 - i][9];
        for (int i = 3; i < 9; i++) cur[i][5] = p[i - 3][5];
        for (int i = 0; i < 3; i++) cur[3 + i][9] = p[8 - i][5];
        x = 3, y = 6;
        cur[x][y] = p[x][y + 2];
        cur[x + 1][y] = p[x][y + 1];
        cur[x + 1][y + 2] = p[x + 2][y + 1];
        cur[x + 2][y] = p[x][y];
        cur[x + 2][y + 1] = p[x + 1][y];
        cur[x + 2][y + 2] = p[x + 2][y];
        cur[x][y + 1] = p[x + 1][y + 2];
        cur[x][y + 2] = p[x + 2][y + 2];
        if (self(self, o + 1, cur)) return true;
        for (int i = 0; i < 3; i++) cur[i][5] = p[i][5];
        for (int i = 3; i < 9; i++) cur[i][5] = p[i][5];
        for (int i = 0; i < 3; i++) cur[3 + i][9] = p[3 + i][9];
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];
        // 5 D
        for (int i = 0; i < 6; i++) cur[i][5] = p[i + 3][5];
        for (int i = 6; i < 9; i++) cur[i][5] = p[11 - i][9];
        for (int i = 0; i < 3; i++) cur[3 + i][9] = p[2 - i][5];
        x = 3, y = 6;
        cur[x][y] = p[x + 2][y];
        cur[x + 1][y] = p[x + 2][y + 1];
        cur[x + 1][y + 2] = p[x][y + 1];
        cur[x + 2][y] = p[x + 2][y + 2];
        cur[x + 2][y + 1] = p[x + 1][y + 2];
        cur[x + 2][y + 2] = p[x][y + 2];
        cur[x][y + 1] = p[x + 1][y];
        cur[x][y + 2] = p[x][y];
        if (self(self, o + 1, cur)) return true;
        for (int i = 0; i < 3; i++) cur[i][5] = p[i][5];
        for (int i = 3; i < 9; i++) cur[i][5] = p[i][5];
        for (int i = 0; i < 3; i++) cur[3 + i][9] = p[3 + i][9];
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];
        // B L
        for (int i = 0; i < 3; i++) {
            cur[0][i + 3] = p[5 - i][0];
            cur[i + 3][0] = p[8][i + 3];
            cur[8][i + 3] = p[5 - i][8];
            cur[i + 3][8] = p[0][i + 3];
        }
        x = 3, y = 9;
        cur[x][y] = p[x][y + 2];
        cur[x + 1][y] = p[x][y + 1];
        cur[x + 1][y + 2] = p[x + 2][y + 1];
        cur[x + 2][y] = p[x][y];
        cur[x + 2][y + 1] = p[x + 1][y];
        cur[x + 2][y + 2] = p[x + 2][y];
        cur[x][y + 1] = p[x + 1][y + 2];
        cur[x][y + 2] = p[x + 2][y + 2];
        if (self(self, o + 1, cur)) return true;
        for (int i = 0; i < 3; i++) {
            cur[0][i + 3] = p[0][i + 3];
            cur[i + 3][0] = p[i + 3][0];
            cur[8][i + 3] = p[8][i + 3];
            cur[i + 3][8] = p[i + 3][8];
        }
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];
        // B R
        for (int i = 0; i < 3; i++) {
            cur[0][i + 3] = p[i + 3][8];
            cur[i + 3][0] = p[0][5 - i];
            cur[8][i + 3] = p[i + 3][0];
            cur[i + 3][8] = p[8][5 - i];
        }
        x = 3, y = 9;
        cur[x][y] = p[x + 2][y];
        cur[x + 1][y] = p[x + 2][y + 1];
        cur[x + 1][y + 2] = p[x][y + 1];
        cur[x + 2][y] = p[x + 2][y + 2];
        cur[x + 2][y + 1] = p[x + 1][y + 2];
        cur[x + 2][y + 2] = p[x][y + 2];
        cur[x][y + 1] = p[x + 1][y];
        cur[x][y + 2] = p[x][y];
        if (self(self, o + 1, cur)) return true;
        for (int i = 0; i < 3; i++) {
            cur[0][i + 3] = p[0][i + 3];
            cur[i + 3][0] = p[i + 3][0];
            cur[8][i + 3] = p[8][i + 3];
            cur[i + 3][8] = p[i + 3][8];
        }
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];
        // F R
        for (int i = 0; i < 3; i++) {
            cur[2][i + 3] = p[5 - i][2];
            cur[i + 3][2] = p[6][i + 3];
            cur[6][i + 3] = p[5 - i][6];
            cur[i + 3][6] = p[2][i + 3];
        }
        x = 3, y = 3;
        cur[x][y] = p[x + 2][y];
        cur[x + 1][y] = p[x + 2][y + 1];
        cur[x + 1][y + 2] = p[x][y + 1];
        cur[x + 2][y] = p[x + 2][y + 2];
        cur[x + 2][y + 1] = p[x + 1][y + 2];
        cur[x + 2][y + 2] = p[x][y + 2];
        cur[x][y + 1] = p[x + 1][y];
        cur[x][y + 2] = p[x][y];
        if (self(self, o + 1, cur)) return true;
        for (int i = 0; i < 3; i++) {
            cur[2][i + 3] = p[2][i + 3];
            cur[i + 3][2] = p[i + 3][2];
            cur[6][i + 3] = p[6][i + 3];
            cur[i + 3][6] = p[i + 3][6];
        }
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];
        // F L
        for (int i = 0; i < 3; i++) {
            cur[2][i + 3] = p[i + 3][6];
            cur[i + 3][2] = p[2][5 - 2];
            cur[6][i + 3] = p[i + 3][2];
            cur[i + 3][6] = p[6][5 - i];
        }
        x = 3, y = 3;
        cur[x][y] = p[x][y + 2];
        cur[x + 1][y] = p[x][y + 1];
        cur[x + 1][y + 2] = p[x + 2][y + 1];
        cur[x + 2][y] = p[x][y];
        cur[x + 2][y + 1] = p[x + 1][y];
        cur[x + 2][y + 2] = p[x + 2][y];
        cur[x][y + 1] = p[x + 1][y + 2];
        cur[x][y + 2] = p[x + 2][y + 2];
        if (self(self, o + 1, cur)) return true;
        for (int i = 0; i < 3; i++) {
            cur[2][i + 3] = p[2][i + 3];
            cur[i + 3][2] = p[i + 3][2];
            cur[6][i + 3] = p[6][i + 3];
            cur[i + 3][6] = p[i + 3][6];
        }
        cur[x][y] = p[x][y];
        cur[x + 1][y] = p[x + 1][y];
        cur[x + 1][y + 2] = p[x + 1][y + 2];
        cur[x + 2][y] = p[x + 2][y];
        cur[x + 2][y + 1] = p[x + 2][y + 1];
        cur[x + 2][y + 2] = p[x + 2][y + 2];
        cur[x][y + 1] = p[x][y + 1];
        cur[x][y + 2] = p[x][y + 2];

        //
        if (ans.size() == 0){
            for (int i = 0; i < 8; i++) {
                int x1 = cor[i][0][0], y1 = cor[i][0][1];
                int x2 = cor[i][1][0], y2 = cor[i][1][1];
                int x3 = cor[i][2][0], y3 = cor[i][2][1];
                
                int ok = 0;

                cur[x1][y1] = p[x2][y2]; 
                cur[x2][y2] = p[x1][y1];
                ok |= check(cur);
                cur[x1][y1] = p[x1][y1]; 
                cur[x2][y2] = p[x2][y2];

                cur[x1][y1] = p[x3][y3]; 
                cur[x3][y3] = p[x1][y1];
                ok |= check(cur);
                cur[x1][y1] = p[x1][y1]; 
                cur[x3][y3] = p[x3][y3];

                cur[x3][y3] = p[x2][y2]; 
                cur[x2][y2] = p[x3][y3];
                ok |= check(cur);
                cur[x3][y3] = p[x3][y3]; 
                cur[x2][y2] = p[x2][y2];
                if (ok) {
                    ans.push_back({p[x1][y1] - '0', p[x2][y2] - '0', p[x3][y3] - '0'});
                }
            }
        }
        return false;
    };

    // if (check(s)) cerr << "ok\n";
    if (dfs(dfs, 0, s)) {
        cout << "No problem\n";
        return;
    } else {
        sort(ans[0].begin(), ans[0].end());
        for (int i = 0; i < 3; i++) {
            cout << ans[0][i] << " \n"[i == 2];
        }
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