/*
 * Author: Ram
 * Date: 2024-05-11
 * Source: https://atcoder.jp/contests/abc353/tasks/abc353_e
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
ll ans;
struct Trie{
    int cnt;
    Trie *son[26];
    Trie(){
        cnt=0;
        for (int i = 0; i < 26; i++)
            son[i] = nullptr;
    }

    ~Trie(){
        for(Trie *nxt: son)
            if(nxt)
                delete nxt;
    }

    void insert(string word){
        Trie *node = this;
        for (auto w : word){
            if (node->son[w - 'a'] == nullptr)
                node->son[w - 'a'] = new Trie();
            node = node->son[w - 'a'];
            ans+=node->cnt;
            node->cnt++;
        }
    }

};
void solve(){
    int n;
    cin>>n;
    ans=0;
    Trie trie{};
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        trie.insert(s);
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}