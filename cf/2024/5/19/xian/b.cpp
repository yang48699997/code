/*
 * Author: Ram
 * Date: 2024-05-19
 * Source: https://www.luogu.com.cn/problem/T455118?contestId=172272
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    double x,y,t,v;
    cin>>x>>y>>t>>v;
    double pi=asin(1)*2;
    double r=sqrt(x*x+y*y);
    double u=-t*v*2*pi;
    double xx=x*cos(u)-y*sin(u);
    double yy=y*cos(u)+x*sin(u);
    double ans=(xx-x)*(xx-x)+(yy-y)*(yy-y);
    ans=sqrt(ans);
    cout<<fixed<<setprecision(8)<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}