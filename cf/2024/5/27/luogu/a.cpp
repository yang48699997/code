#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

string s1,s2;
int n,m;
const int N=1e6+5;
int nxt[N];
void solve(){
    cin>>s1>>s2;
    n=s1.length();
    m=s2.length();
    int j=0;
    nxt[j]=0;
    for(int i=1;i<m;i++){
        while(j>0&&s2[i]!=s2[j])j=nxt[j-1];
        if(s2[i]==s2[j])j++;
        nxt[i]=j;
    }
    j=0;
    for(int i=0;i<n;i++){
        while(j>0&&s1[i]!=s2[j])j=nxt[j-1];
        if(s1[i]==s2[j])j++;
        if(j==m){
            cout<<i-m+2<<endl;
        }
    }
    for(int i=0;i<m;i++)cout<<nxt[i]<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}