#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Trie{
    int cnt;
    Trie *son[26];
    int sg;
    Trie() {
        cnt = 0;
        sg = 0;
        for (int i = 0; i < 26; i++) son[i] = nullptr;
    }
    void insert(string word){
        Trie *node = this;
        for (auto w : word){
            if (node->son[w - 'a'] == nullptr) node->son[w - 'a'] = new Trie();
            node = node->son[w - 'a'];
        }
        node -> sg = 0;
    }
    void work1() {
        vector<int> p;
        for (int i = 0; i < 26; i++) {
            if (son[i] == nullptr) continue;
            son[i] -> work1();
            p.push_back(son[i] -> sg);
        }
        sort(p.begin(), p.end());
        int m = unique(p.begin(), p.end()) - p.begin();
        sg = m;
        for (int i = 0; i < m; i++) {
            if (p[i] != i) {
                sg = i;
                break;
            }
        }
        if (p.empty()) sg = 1;
    }
    void work2() {
        vector<int> p;
        for (int i = 0; i < 26; i++) {
            if (son[i] == nullptr) continue;
            son[i] -> work2();
            p.push_back(son[i] -> sg);
        }
        sort(p.begin(), p.end());
        int m = unique(p.begin(), p.end()) - p.begin();
        sg = m;
        for (int i = 0; i < m; i++) {
            if (p[i] != i) {
                sg = i;
                break;
            }
        }
        if (p.empty()) sg = 0;
    }
};


void solve() {
    int n, k;
    cin >> n >> k;
    Trie t = {};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        t.insert(s);
    }
    t.work1();
    int sg1 = 0;
    for (int i = 0; i <26; i++) {
        if (t.son[i] != nullptr) sg1 |= t.son[i] -> sg;
    }
    t.work2();
    int sg2 = 0;
    for (int i = 0; i <26; i++) {
        if (t.son[i] != nullptr && t.son[i] -> sg == 0) sg2 = 1;
    }
    cerr << sg1 << " " << sg2 << "\n";
    if (sg1 && sg2) cout << "First\n";
    else if (sg1) {
        if (k & 1) cout << "First\n";
        else cout << "Second\n";
    } else if (sg2) {
        cout << "Second\n";
    } else {
        cout << "Second\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}