#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
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
            node->cnt++;
        }
    }
    void erase(string word){
        Trie *node = this;
        for (auto w : word){
            node = node->son[w - 'a'];
            node->cnt--;
        }
    }
    
    int lcp(string word){
        Trie* node=this;
        int res=0;
        for(auto w:word){
            node=node->son[w-'a'];
            if(node->cnt==0)return res;
            else res++;
        }
        return res;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<string> s(n);
    Trie trie=Trie();
    for(int i=0;i<n;i++){
        cin>>s[i];
        trie.insert(s[i]);
    }
    for(int i=0;i<n;i++){
        trie.erase(s[i]);
        cout<<trie.lcp(s[i])<<endl;
        trie.insert(s[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}