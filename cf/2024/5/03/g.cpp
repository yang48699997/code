/*
 * Author: Ram
 * Date: 2024-05-03
 * Source: https://codeforces.com/contest/1968/problem/G2
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=2e5+5;
int T;
int n;
string s;
int nxt[N];
void get_nxt(){
    nxt[0]=n;
    int a=0,p=0;
    for(int i=1;i<n;i++){
        if(i>=p||i+nxt[i-a]>=p){
            if(i>=p)p=i;
            while(p<n&&s[p-i]==s[p])p++;
            nxt[i]=p-i;
            a=i;
        }else nxt[i]=nxt[i-a];
    }
}
void solve(){
    int l,r;
    cin>>n>>l>>r>>s;
    get_nxt();

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
        cout<<endl;
    }
    return 0;
}