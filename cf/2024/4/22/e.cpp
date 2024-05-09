/*
 * Author: Ram
 * Date: 2024-04-22
 * Source: https://codeforces.com/contest/1957/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
const int mod=1e9+7;
const int N=1e6+7;
int m,pri[N],v[N];
ll pre[N];
void init(){
    for(int i=0;i<N;i++)v[i]=0,pre[i]=0;
    m=0;
    for(int i=2;i<N;i++){
        if(!v[i])pri[m++]=i;
        for(int j=0;pri[j]*i<N;j++){
            v[pri[j]*i]=1;
            if(i%pri[j]==0)break;
        }
    }
    for(int i=1;i<N;i++){
        ll p=0;
        if(i==4){
            ll j=i;
            while(j<N){
                pre[j]+=(j/i*2%4-p)%mod;
                p=j/i*2%4;
                j+=i;
            }
        }else if(!v[i]){
            ll j=i;
            while(j<N){
                pre[j]+=(j/i*(i-1)%i-p)%mod;
                p=j/i*(i-1)%i;
                j+=i;
            }
        }
    }
    for(int i=1;i<N;i++){
        pre[i]=(pre[i-1]+pre[i])%mod;
        if(pre[i]<0)pre[i]+=mod;
    }
    for(int i=1;i<N;i++){
        pre[i]=(pre[i-1]+pre[i])%mod;
        if(pre[i]<0)pre[i]+=mod;
    }
}
void solve(){
    int n;
    cin>>n;
    cout<<pre[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    init();
    while(T--){
        solve();
        cout<<endl;
    }
    return 0;
}