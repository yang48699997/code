/*
 * Author: Ram
 * Date: 2024-04-15
 * Source: https://codeforces.com/gym/105053/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int gcd(int x,int y){
    while(y){
        int temp=y;
        y=x%y;
        x=temp;
    }
    return x;
}
void solve(){
    int n;
    cin>>n;
    int g=-1;
    map<int,int> cnt;
    int sum=0;
    bool n0=true;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        sum+=x;
        if(x==0)n0=false;
        cnt[x]++;
        if(g==-1)g=y;
        else g=gcd(g,y);
    }
    bitset<200005> bs(1);
    for(auto it=cnt.begin();it!=cnt.end();it++){
        int x=it->first,c=it->second;
        for(int i=0;1<<i<=c;i++){
            bs|=bs<<(x*(1<<i));
            c-=1<<i;
        }
        bs|=bs<<(x*c);
    }
    int mx,mi;
    if(n0)mi=1,mx=sum-1;
    else mi=0,mx=sum;
    for(int i=mi;i<=mx;i++){
        if(bs.test(i)&&abs(sum-2*i)%g==0){
            cout<<"Y";
            return;
        }
    }
    cout<<"N";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}