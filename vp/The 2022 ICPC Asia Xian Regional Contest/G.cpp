#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Trie{
    int cnt;
    Trie *son[26];
    Trie() {
        cnt=0;
        for (int i = 0; i < 26; i++) son[i] = nullptr;
    }
    ~Trie() {
        for(Trie *nxt: son) if(nxt) delete nxt;
    }
    void insert(string word){
        Trie *node = this;
        for (auto w : word){
            if (node->son[w - 'a'] == nullptr) node->son[w - 'a'] = new Trie();
            node = node->son[w - 'a'];
        }
        node->cnt++;
    }
    int search(string word){
        Trie *node = this;
        for (auto w : word){
            if (node->son[w - 'a'] == nullptr) return false;
            node = node->son[w - 'a'];
            if (node -> cnt == 0) return false;
        }
        return 1;
    }
    bool startsWith(string prefix){
        Trie *node = this;
        for (auto w : prefix){
            if (node->son[w - 'a'] == nullptr) return false;
            node = node->son[w - 'a'];
        }
        return true;
    }
};

int check(string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[0]) return 0;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> same(26);
    vector<int> p(n);

    Trie t = {};
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        t.insert(s[i]);
        int ok = 1;
        for (int j = 1; j < s[i].size(); j++) {
            if (s[i][j] != s[i][0]) {
                ok = 0;
                break;
            }
        }
        p[i] = ok;
        if (ok) same[s[i][0] - 'a'].push_back(s[i].size());
    }

    int ans = 0;

    for (int i = 0; i < 26; i++) {
        sort(same[i].begin(), same[i].end());
        same[i].erase(unique(same[i].begin(), same[i].end()), same[i].end());
        while (!same[i].empty() && same[i].back() != same[i].size()) same[i].pop_back();
        ans = max(ans, (int)same[i].size());
    }

    const int mx = 1e5;
    for (int i = 0; i < n; i++) {
        int ok = 1;
        for (int j = 0; j < s[i].size() && ok; j++) {
            if (check(s[i].substr(j))) {
                if (same[s[i][j] - 'a'].size() >= s[i].size() - j) break;
                else ok = 0;
                break;
            }
            ok &= t.search(s[i].substr(j));
        }
        if (ok) ans = max(ans, (int)s[i].size());
    }

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}