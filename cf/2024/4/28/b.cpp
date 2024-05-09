/*
 * Author: Ram
 * Date: 2024-04-28
 * Source: https://codeforces.com/contest/1937/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<string> s(2);
    cin>>s[0]>>s[1];
    int c=n-1;
    for(int i=0;i<n-1;i++){
        if(s[0][i+1]>s[1][i]){
            c=i;
            break;
        }
    }
    int ans=1;
    for(int i=c-1;i>=0;i--){
        if(s[1][i]==s[0][i+1])ans++;
        else break;
    }
    for(int i=0;i<=c;i++)cout<<s[0][i];
    for(int i=c;i<n;i++)cout<<s[1][i];
    cout<<endl<<ans;
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