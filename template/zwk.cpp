#include<bits/stdc++.h>

using namespace std;

template<class T>
struct ZWK{
    int n,N;
    vector<T> tree;
    ZWK(vector<T> &a){
        n=a.size();
        N=(1<<(32-__builtin_clz(n)));
        tree.resize(N<<1);
        for(int i=0;i<n;i++)tree[i+1+N]=a[i];
        for(int i=N;i;i--)tree[i]=tree[i<<1]+tree[i<<1|1];
    }
    void update(int index,T x){
        int i=index+1+N;
        x=x-tree[i];
        while(i){
            tree[i]+=x;
            i>>=1;
        }
    }
    T query(int l,int r){
        l+=N;
        r+=N+2;
        for(;)
    }
};