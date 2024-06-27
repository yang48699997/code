/*
 * Author: Ram
 * Date: 2024-05-17
 * Source: https://codeforces.com/problemset/problem/1025/C
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    int pre=0;
    for(int i=pre;i<n;){
        i++;
        while(i<n&&s[i]!=s[i-1])i++;
        if(i==n)break;
        s+=s.substr(pre,i-pre);
        pre=i;
    }
    int ans=0;
    for(int i=pre;i<s.length();){
        int j=i+1;
        int res=1;
        while(j<s.length()&&s[j]!=s[j-1])j++,res++;
        i=j;
        ans=max(res,ans);
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>T;
    T=1;
    while(T--){
        solve();
        cout<<endl;
    }
    return 0;
}