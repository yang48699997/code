/*
 * Author: Ram
 * Date: 2024-05-10
 * Source: https://codeforces.com/contest/1971/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x=(a-c)*(b-c);
    int y=(a-d)*(b-d);
    if(x<0&&y>0)cout<<"YES";
    else if(x>0&&y<0)cout<<"YES";
    else cout<<"NO";
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