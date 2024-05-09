#include<bits/stdc++.h>

using namespace std;

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
        }
        node->cnt++;
    }

    int search(string word){
        Trie *node = this;
        for (auto w : word){
            if (node->son[w - 'a'] == nullptr)
                return false;
            node = node->son[w - 'a'];
        }
        return node->cnt;
    }

    bool startsWith(string prefix){
        Trie *node = this;
        for (auto w : prefix){
            if (node->son[w - 'a'] == nullptr)
                return false;
            node = node->son[w - 'a'];
        }
        return true;
    }
};

int main(){
    Trie trie={};
    return 0;
}
