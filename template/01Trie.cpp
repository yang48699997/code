#include<bits/stdc++.h>

using namespace std;

struct Trie {
    static const int N = 31;
    int cnt;
    Trie *son[2];
    Trie(){
        cnt=0;
        for (int i = 0; i < 2; i++) son[i] = nullptr;
    }

    ~Trie(){
        for(Trie *nxt: son) {
            if(nxt) delete nxt;
        }
    }

    string to_bin(int x){
        string res;
        for (int i = 0; i < N; i++){
            int cur = x % 2;
            x /= 2;
            res += '0' + cur;
        }
        reverse(res.begin() ,res.end());
        return res;
    }

    int to_int(string word){
        int res=0;
        for(int i = 0; i < N; i ++){
            res = res * 2 + word[ i ] - '0' ;
        }
        return res;
    }

    void insert(int x){
        string word = to_bin(x);
        Trie *node = this;
        for (auto w : word){
            if (node -> son[w - '0'] == nullptr) node -> son[w - '0'] = new Trie();
            node = node->son[w - '0'];
            node -> cnt++;
        }
        this -> cnt++;
    }

    int search(int x){
        string word = to_bin(x);
        Trie *node = this;
        for (auto w : word){
            if (node -> son[w - '0'] == nullptr)
                return false;
            node = node -> son[w - '0'];
        }
        return node -> cnt;
    }

    void erase(int x){
        string word = to_bin(x);
        Trie *node = this;
        for (auto w : word){
            node = node -> son[w - '0'];
            node -> cnt--;
        }
        this -> cnt--;
        return;
    }

    int xor_max(int x){
        string word = to_bin(x);
        Trie *node = this;
        int res=0;
        for (auto w : word){
            if (node->son[(w - '0') ^ 1] == nullptr || node -> son[(w - '0') ^ 1] -> cnt == 0){
                node = node -> son[w - '0'];
                res = res * 2;
            }
            else{
                node = node -> son[(w - '0') ^ 1];
                res = res * 2 + 1;
            } 
        }
        return res;
    }
};

