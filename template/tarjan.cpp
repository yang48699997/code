#include <bits/stdc++.h>
using namespace std;

struct Tarjan {
    int tot, top, cnt;
    int n;
    vector<int> dfn, low, stk, instk, scc, siz;
    vector<vector<int>> e;
    Tarjan(int n_) : n(n_), tot(0), top(0), cnt(0), dfn(n_ + 1), low(n_ + 1), stk(n_ + 1), instk(n_ + 1), scc(n_ + 1), siz(n_ + 1), e(n_ + 1) {} 
    void addEdge(int u, int v) {
        e[u].push_back(v);
    }
    void init() {
        tot = top = cnt = 0;
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        instk.assign(n + 1, 0);
        siz.assign(n + 1, 0);
    }
    void tarjan(int x) {
        dfn[x] = low[x] = ++tot;
        stk[top++] = x;
        instk[x] = 1;
        for (int nxt : e[x]) {
            if (!dfn[nxt]) {
                tarjan(nxt);
                low[x] = min(low[x], low[nxt]);
            } else if (instk[nxt]) {
                low[x] = min(low[x], dfn[nxt]);
            }
        }
        if (dfn[x] == low[x]) {
            cnt++;
            int y = 0;
            while (y != x) {
                y = stk[--top];
                instk[y] = 0;
                scc[y] = cnt;
                siz[cnt]++;
            }
        }
        return;
    }
    void work() {
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) tarjan(i);
        }
        return;
    }  
};