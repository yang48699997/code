/*
 * Author: Ram
 * Date: 2024-05-21
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int T;
double ans;
using ll = long long;
void cal(pair<ll,ll> &a,pair<ll,ll> &b){
    double d1=abs(a.first-b.first)+abs(a.second-b.second);
    double d2=a.first-b.first;
    double d3=a.second-b.second;
    double d=d2*d2+d3*d3;
    d=sqrt(d);
    ans=max(d1/d,ans);
}

void solve(){
    int n;
    cin>>n;
    vector<pair<ll,ll>> p(n);
    for(int i=0;i<n;i++)cin>>p[i].first>>p[i].second;
    sort(p.begin(),p.end(),[](auto &a,auto &b){
        if(a.second-a.first!=b.second-b.first)return a.second-a.first<b.second-b.first;
        return a.second+a.first<b.second+b.first;
    });
    ans=0;
    for(int i=0;i<n-1;i++)cal(p[i],p[i+1]);
    sort(p.begin(),p.end(),[](auto &a,auto &b){
        if(-a.second-a.first!=-b.second-b.first)return -a.second-a.first<-b.second-b.first;
        return a.second-a.first<b.second-b.first;
    });
    for(int i=0;i<n-1;i++)cal(p[i],p[i+1]);
    cout<<fixed<<setprecision(10)<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)solve(),cout<<endl;
    cout<<endl;
    return 0;
}