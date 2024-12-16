#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 1e9;

struct Trie{
    int cnt, mi;
    Trie *son[26];
    Trie() {
        cnt = 0;
        mi = inf;
        for (int i = 0; i < 26; i++) son[i] = nullptr;
    }
    ~Trie() {
        for(Trie *nxt: son) if(nxt) delete nxt;
    }
    int insert(string word){
        Trie *node = this;
        int n = word.size();
        this -> mi = min(mi, n);
        int res = inf;
        for (auto w : word){
            n--;
            if (node->son[w - 'a'] == nullptr) node->son[w - 'a'] = new Trie();
            node = node->son[w - 'a'];
            res = min(res, n + node -> mi);
            node -> mi = min(node -> mi, n);
        }
        node->cnt++;
        return res;
    }
};


void solve() {
    int n;
    cin >> n;

    Trie t = {};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int ans = s.size();

        ans = min(ans, t.insert(s));
        cout << ans << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}