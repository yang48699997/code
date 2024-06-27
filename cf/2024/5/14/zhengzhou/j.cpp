/*
 * Author: Ram
 * Date: 2024-05-14
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=1e5+5;
int T;
int p;
int v[N],prim[N];
void init(){
    p=0;
    for(int i=1;i<N;i++)v[i]=0;
    for(int i=2;i<N;i++){
        if(!v[i])prim[p++]=i;
        for(int j=0;prim[j]*i<N;j++){
            v[i*prim[j]]=1;
            if(i%prim[j]==0)break;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(5);
    for(int i=0;i<5;i++){
        a[i]=n%10;
        n/=10;
    }
    sort(a.begin(),a.end());
    do{
        if(a[0]==0)continue;
        int res=a[0];
        for(int i=1;i<5;i++)res=res*10+a[i];
        if(v[res]){
            cout<<res;
            return;
        }
    }while(next_permutation(a.begin(),a.end()));
    cout<<-1;
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