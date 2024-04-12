#include <bits/stdc++.h>
#define endl '\n'

using ll = long long;
using namespace std;

struct ex_KMP{
    string s1,s2;
    vector<int> nxt,ex;
    int n,m;
    ex_KMP(string s1,string s2):nxt(s2.length()),ex(s1.length()){
        n=s1.length();
        m=s2.length();
        this->s1=s1;
        this->s2=s2;
        int a=0,p=0;
        nxt[0]=m;
        for(int i=1;i<m;i++){
            if(i>=p||i+nxt[i-a]>=p){
                if(i>=p)p=i;
                while(p<m&&s2[p]==s2[p-i])p++;
                nxt[i]=p-i;
                a=i;
            }else nxt[i]=nxt[i-a];
        }
        a=0,p=0;
        for(int i=0;i<n;i++){
            if(i>=p||i+nxt[i-a]>=p){
                if(i>=p)p=i;
                while(p<n&&p-i<m&&s1[p]==s2[p-i])p++;
                ex[i]=p-i;
                a=i;
            }else ex[i]=nxt[i-a];
        }
    }
};
