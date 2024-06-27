/*
 * Author: Ram
 * Date: 2024-05-19
 * Source: https://www.luogu.com.cn/problem/T455122?contestId=172272
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    double x,y;
    cin>>x>>y;
    double xx=x/2+y/2;
    double p=3;
    p=sqrt(p);
    double yy=p*x/2-p*y/2;
    cout<<fixed<<setprecision(8)<<xx<<' '<<yy;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}